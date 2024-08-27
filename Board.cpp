#include "Board.h"
#include <QDebug>
#include <QTimer>

#include <QThread>


Board::Board(QObject *parent)
    : QObject{parent}, m_boardSize(10), m_currentIndex(-1), m_isBusy(false), m_thread(new QThread)
{
    for(int i = 0; i < m_boardSize * m_boardSize; i++){
        m_boardData.append(new Cell(""));
    }
    emit boardDataChanged();

}

Board::~Board()
{
    for(int i = 0; i < m_boardSize * m_boardSize; i++){
        if(m_boardData[i] != nullptr){
            delete m_boardData[i];
        }
    }
}

int Board::boardSize() const
{
    return m_boardSize;
}


bool Board::makeMove(int number, QString player)
{
    int x = number / 10;
    int y = number % 10;
    if(m_boardData[number]->value() != "")
        return false;
    m_boardData[number]->setValue(player);
    m_history.append(number);
    // m_currentIndex++;
    emit boardDataChanged();
    return checkWin(x, y, player);
}

void Board::resetBoard()
{
    for (int var = 0; var < m_boardSize * m_boardSize; ++var) {
        m_boardData[var]->setValue("");
    }
    emit boardDataChanged();
}

bool Board::isFull()
{
    for (int var = 0; var < m_boardSize * m_boardSize; ++var) {
        if(m_boardData[var]->value() == "")
            return false;
    }
    return true;
}

QString Board::getValue(int index)
{
    return m_boardData[index]->value();
}

bool Board::botMove(QString mode)
{
    int index = 0;
    m_isBusy = true;
    emit isBusyChanged();
    if(mode == "Easy"){
        do{
            index = rand() % (m_boardSize * m_boardSize);
        } while(m_boardData[index]->value() != "");

        m_boardData[index]->setValue("X");
        m_history.append(index);
        m_isBusy = false;
        emit boardDataChanged();
        emit botMoveSuccessful(index);
        emit isBusyChanged();
    }
    else if (mode == "Normal"){
        m_thread = QThread::create([&](){
            index = findBestMove(MAX_DEPTH - 1);
            m_boardData[index]->setValue("X");
            m_history.append(index);
            m_isBusy = false;
            emit boardDataChanged();
            emit botMoveSuccessful(index);
            emit isBusyChanged();
        });

        m_thread->start();
        connect(m_thread, &QThread::finished, m_thread, &QThread::deleteLater);
    }
    else {      // hard mode
        m_thread = QThread::create([&](){
            index = findBestMove(MAX_DEPTH);
            m_boardData[index]->setValue("X");
            m_history.append(index);
            m_isBusy = false;
            emit boardDataChanged();
            emit botMoveSuccessful(index);
            emit isBusyChanged();
        });

        m_thread->start();
        connect(m_thread, &QThread::finished, m_thread, &QThread::deleteLater);
    }

    return checkWin(index / m_boardSize, index % m_boardSize, "X");
}


int rowMove[8] = { 1, -1, 0, 0, 1, -1, -1, 1 };
int colMove[8] = { 0, 0, 1, -1, 1, -1, 1, -1 };
bool Board::checkLine(int x, int y, int pos1, int pos2, QString player)
{
    // bool block = false;
    QVector<int> containLines;
    containLines.push_back(x * m_boardSize + y);        // push first index that we set
    int count = 1;
    int row = x + rowMove[pos1];
    int col = y + colMove[pos1];
    int index = row * m_boardSize + col;
    while (row >= 0 && row < m_boardSize && col >= 0 && col < m_boardSize)
    {
        if (m_boardData[index]->value() == player) {
            count++;
            containLines.push_back(index);
            row += rowMove[pos1];
            col += colMove[pos1];
            index = row * m_boardSize + col;
        }
        else
        {
            // if(m_boardData[index]->value() != ""){
            //     block = true;
            // }
            break;
        }
    }

    row = x + rowMove[pos2];
    col = y + colMove[pos2];
    index = row * m_boardSize + col;
    while (row >= 0 && row < m_boardSize && col >= 0 && col < m_boardSize)
    {
        if (m_boardData[index]->value() == player) {
            count++;
            containLines.push_back(index);
            row += rowMove[pos2];
            col += colMove[pos2];
            index = row * m_boardSize + col;
        }
        else
        {
            // if(m_boardData[index]->value() != ""){
            //     block = true;
            // }
            break;
        }
    }
    // if((block && count == 5) || (!block && count == 4)){
    //     emit winningState(containLines);
    //     qDebug() << "The winning linne is";
    //     qDebug() << containLines;
    //     return true;
    // }
    // return false;
    if(count >= 4){
        emit winningState(containLines);
        return true;
    }
    return false;
}

bool Board::checkWin(int x, int y, QString player)
{
    for (int i = 0; i < 8; i += 2) {
        if (checkLine(x, y, i, i + 1, player)) {
            return true;
        }
    }
    return false;
}

QList<Cell *> Board::boardData() const
{
    return m_boardData;
}

int Board::redo()
{
    if(m_currentIndex == m_history.size() - 1){
        return -1;
        qDebug() << "Can not move anymore because the match end";
    }
    else {
        m_currentIndex++;
        QString character = (m_currentIndex  % 2) == 0 ? "O" : "X";
        int x = m_history[m_currentIndex] / 10;
        int y = m_history[m_currentIndex] % 10;
        m_boardData[m_history[m_currentIndex]]->setValue(character);
        // makeMove(m_history[m_currentIndex], character);
        checkWin(x, y, character);
        emit boardDataChanged();
        return m_history[m_currentIndex];
    }
}

int Board::undo()
{
    if(m_currentIndex == - 1){
        qDebug() << "Can not undo because no more player get move";
    }
    else {
        m_boardData[m_history[m_currentIndex--]]->setValue("");
        // makeMove(m_history[m_currentIndex--], "");
        emit boardDataChanged();
        // return -1 means that no more move can undo
        return m_currentIndex == -1 ? -1 : m_history[m_currentIndex];
    }
    return -1;
}


void Board::clearReplay()
{
    qDebug() << "Clear board successfully";
    m_history.clear();
    m_currentIndex = -1;
}


int Board::undoInMatch(bool playbot)
{
    if(m_history.size() < 1){
        qDebug() << "Cannot undo anymore";
        return -1;
    }
    int index = m_history[m_history.size() - 1];
    m_boardData[index]->setValue("");
    m_history.removeLast();
    if(playbot){
        index = m_history[m_history.size() - 1];
        m_boardData[index]->setValue("");
        m_history.removeLast();
    }
    emit boardDataChanged();
    return index;
}

bool Board::isBusy() const
{
    return m_isBusy;
}

void Board::setIsBusy(bool newIsBusy)
{
    if (m_isBusy == newIsBusy)
        return;
    m_isBusy = newIsBusy;
    emit isBusyChanged();
}

QString Board::getValue(int x, int y)
{
    return m_boardData[x * m_boardSize + y]->value();
}

int Board::minimax(int depth, int alpha, int beta, bool isMaximizing,  int maxDepth)
{
    int score = evaluate();

    // Kiểm tra điều kiện kết thúc
    if (score == 10) return score - depth;
    if (score == -10) return score + depth;
    if (depth == maxDepth) return 0; // Hoặc kiểm tra nếu bảng đầy

    if (isMaximizing) {
        int best = -20;
        for (int i = 0; i < m_boardSize; i++) {
            for (int j = 0; j < m_boardSize; j++) {
                if (isValidMove(i, j)) {
                    m_boardData[i * m_boardSize + j]->setValueWithoutSignal("X");
                    best = std::max(best, minimax(depth + 1, alpha, beta, false, maxDepth));
                    m_boardData[i * m_boardSize + j]->setValueWithoutSignal("");
                    alpha = std::max(alpha, best);
                    if (beta <= alpha)
                        return best;
                }
            }
        }
        return best;
    } else {
        int best = 20;
        for (int i = 0; i < m_boardSize; i++) {
            for (int j = 0; j < m_boardSize; j++) {
                if (isValidMove(i, j)) {
                    m_boardData[i * m_boardSize + j]->setValueWithoutSignal("O");
                    best = std::min(best, minimax(depth + 1, alpha, beta, true, maxDepth));
                    m_boardData[i * m_boardSize + j]->setValueWithoutSignal(""); // Undo move
                    beta = std::min(beta, best);
                    if (beta <= alpha)
                        return best;
                }
            }
        }
        return best;
    }
}

int Board::evaluate()
{
    const int WINNING_LENGTH = 4;

    for (int row = 0; row < m_boardSize; row++) {
       for (int col = 0; col < m_boardSize - WINNING_LENGTH; col++) {
           if (getValue(row, col) == getValue(row, col + 1) &&
               getValue(row, col) == getValue(row, col + 2) &&
               getValue(row, col) == getValue(row, col + 3) &&
               getValue(row, col) == getValue(row, col + 4)) {
               if (getValue(row, col) == "X")
                   return +10;
               else if (getValue(row, col) == "O")
                   return -10;
           }
       }
    }

    for (int col = 0; col < m_boardSize; col++) {
       for (int row = 0; row < m_boardSize - WINNING_LENGTH; row++) {
           if (getValue(row, col) == getValue(row + 1, col) &&
               getValue(row, col) == getValue(row + 2, col) &&
               getValue(row, col) == getValue(row + 3, col) &&
               getValue(row, col) == getValue(row + 4, col)) {
               if (getValue(row, col) == "X")
                   return +10;
               else if (getValue(row, col) == "O")
                   return -10;
           }
       }
    }

    // Check diagonals
    for (int row = 0; row < m_boardSize - WINNING_LENGTH; row++) {
       for (int col = 0; col < m_boardSize - WINNING_LENGTH; col++) {
           if (getValue(row, col) == getValue(row + 1, col + 1) &&
               getValue(row, col) == getValue(row + 2, col + 2) &&
               getValue(row, col) == getValue(row + 3, col + 3) &&
               getValue(row, col) == getValue(row + 4, col + 4)) {
               if (getValue(row, col) == "X")
                   return +10;
               else if (getValue(row, col) == "O")
                   return -10;
           }
       }
    }

    for (int row = WINNING_LENGTH; row < m_boardSize; row++) {
       for (int col = 0; col < m_boardSize - WINNING_LENGTH; col++) {
           if (getValue(row, col) == getValue(row - 1, col + 1) &&
               getValue(row, col) == getValue(row - 2, col + 2) &&
               getValue(row, col) == getValue(row - 3, col + 3) &&
               getValue(row, col) == getValue(row - 4, col + 4)) {
               if (getValue(row, col) == 'X')
                   return +10;
               else if (getValue(row, col) == 'O')
                   return -10;
           }
       }
    }

    // No winner
    return 0;
}


int Board::findBestMove(int maxDepth)
{
    int bestVal = std::numeric_limits<int>::min();
    std::pair<int, int> bestMove = {-1, -1};

    for (int i = 0; i < m_boardSize; i++) {
        for (int j = 0; j < m_boardSize; j++) {
            if (isValidMove(i, j)) {
                m_boardData[i * m_boardSize + j]->setValueWithoutSignal("X");
                int moveVal = minimax(0, -20, 20, false, maxDepth);
                m_boardData[i * m_boardSize + j]->setValueWithoutSignal(""); // Undo move

                if (moveVal > bestVal) {
                    bestMove = {i, j};
                    bestVal = moveVal;
                }
            }
        }
    }
    return bestMove.first * m_boardSize + bestMove.second;
}

bool Board::isValidMove(int x, int y)
{
    return (x >= 0 && x < m_boardSize && y >= 0 && y < m_boardSize && m_boardData[x * m_boardSize + y]->value() == "");
}
