#ifndef BOARD_H
#define BOARD_H

#include <QObject>
#include <QList>
#include <QString>
#include "Cell.h"
#include <QVector>
#include <QThread>

const int MAX_DEPTH = 5;

class Board : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int boardSize READ boardSize CONSTANT)
    Q_PROPERTY(QList<Cell*> boardData READ boardData NOTIFY boardDataChanged)
    Q_PROPERTY(bool isBusy READ isBusy WRITE setIsBusy NOTIFY isBusyChanged FINAL)
public:
    explicit Board(QObject *parent = nullptr);
    ~Board();

    int boardSize() const;


    Q_INVOKABLE bool makeMove(int number, QString player);
    Q_INVOKABLE void resetBoard();
    Q_INVOKABLE bool isFull();
    Q_INVOKABLE QString getValue(int index);
    Q_INVOKABLE bool botMove(QString mode);


    QList<Cell *> boardData() const;

    // Q_INVOKABLE void replay();
    Q_INVOKABLE int redo();
    Q_INVOKABLE int undo();
    Q_INVOKABLE void clearReplay();
    Q_INVOKABLE int undoInMatch(bool playbot);

    bool isBusy() const;
    void setIsBusy(bool newIsBusy);


    // for bot find move
    QString getValue(int x, int y);
    int minimax(int depth, int alpha, int beta, bool isMaximizing, int maxDepth);
    int evaluate();
    int evaluateLine(QVector<QString>& line);
    int findBestMove(int maxDepth);
    bool isValidMove(int x, int y);

signals:
    void boardDataChanged();
    void botMoveSuccessful(int index);
    void winningState(QVector<int> indecies);


    void isBusyChanged();

private:
    bool checkLine(int x, int y, int pos1, int pos2, QString player);
    bool checkWin(int x, int y, QString player);

    int m_boardSize;
    QList<Cell *> m_boardData;

    QList<int> m_history;
    int m_currentIndex;

    bool m_isBusy;
    QThread* m_thread;
};

#endif // BOARD_H
