#include "PlayerController.h"
#include <QDebug>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression>

PlayerController::PlayerController(QObject *parent)
    : QObject{parent}, m_currentPlayer1(nullptr), m_currentPlayer2(nullptr)
{

    m_temp = new Player();
    m_currentPlayer1 = m_temp;
    m_currentPlayer2 = m_temp;

}


PlayerController::~PlayerController()
{
    for (int var = 0; var < m_players.count(); ++var) {
        if(m_players[var] != nullptr){
            delete m_players[var];
        }
    }
    m_currentPlayer1 = nullptr;
    m_currentPlayer2 = nullptr;
}

Player* PlayerController::addPlayer(QString &name)
{
    Player* temp;
    if(nameExisted[name] == false){
        temp = new Player(name, 0, 0, 0);
        m_players.append(temp);
        nameExisted[name] = true;
        emit playersChanged();
    }
    else {
        for(auto player : m_players){
            if(player->nickName() == name){
                temp = player;
                break;
            }
        }
    }
    return temp;
}

void PlayerController::getFromFile(const QString &path)
{
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        return;
    }


    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList data = line.split(" ");
        if (data.size() == 4) {
            m_players.append(new Player(data[0], data[1].toInt(), data[2].toInt(), data[3].toInt()));
            nameExisted[data[0]] = true;
        } else {
            qDebug() << line << " is not in the correct format";
            continue;
        }
    }
    file.close();
    emit playersChanged();
}

void PlayerController::saveToFile(const QString &path)
{
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        return;
    }
    if(m_players.count() == 0){
        qDebug() << "No play to save";
        return;
    }

    for(auto player : m_players){
        QTextStream out(&file);
        out << player->nickName() << " " << player->wins() << " " << player->draws() << " " << player->looses() << "\n";
    }
    file.close();
}

QList<Player *> PlayerController::players() const
{
    return m_players;
}

void PlayerController::setPlayers(const QList<Player *> &newPlayers)
{
    if (m_players == newPlayers)
        return;
    m_players = newPlayers;
    emit playersChanged();
}

QList<Player*> PlayerController::search(const QString &name)
{
    QList<Player*> results;
    for (auto player : m_players) {
        if (player->nickName().contains(name, Qt::CaseInsensitive)) {
            results.append(player);
        }
    }
    return results;
}

QList<Player*> PlayerController::searchRank(int rank, const QString& name)
{
    // if search player don't have anyone --> same rank will show all players in particular rank chose in combo box
    // if the list in search is not empty --> show people in this list that has the same rank chose in combo box
    QList<Player*> results;
    if(name == ""){
        for (auto player : m_players) {
            if (player->rank() == rank) {
                results.append(player);
            }
        }
    }
    else{
        for (auto player : search(name)) {
            if (player->rank() == rank) {
                results.append(player);
            }
        }
    }
    return results;
}

QString PlayerController::checkPlayer(const QString name1, const QString name2)
{
    if(name1.isEmpty() || name2.isEmpty()){
        return QString("Nick name can not be blank");
    }
    if(name1 == name2){
        return QString("2 players cannot have the same name");
    }
    // nickname can not contains space and maximum is 32 character
    QRegularExpression regex("^[\\S]{1,32}$");
    if(regex.match(name1).hasMatch() && (name2 == "BOT" || regex.match(name2).hasMatch())){
        return QString("Success");
    }
    else {
        return QString("Cannot contains space and maximun is 32 characters");
    }
}

Player *PlayerController::currentPlayer1() const
{
    return m_currentPlayer1;
}

void PlayerController::setCurrentPlayer1(Player *newCurrentPlayer1)
{
    if (m_currentPlayer1 == newCurrentPlayer1)
        return;
    m_currentPlayer1 = newCurrentPlayer1;
    emit currentPlayer1Changed();
}

Player *PlayerController::currentPlayer2() const
{
    return m_currentPlayer2;
}

void PlayerController::setCurrentPlayer2(Player *newCurrrentPlayer2)
{
    if (m_currentPlayer2 == newCurrrentPlayer2)
        return;
    m_currentPlayer2 = newCurrrentPlayer2;
    emit currentPlayer2Changed();
}

void PlayerController::setCurrentPlayer(QString name1, QString name2)
{
    if(name2 == "BOT"){
        // m_currentPlayer2 = nullptr;
    }
    else{
        m_currentPlayer2 = addPlayer(name2);
        emit currentPlayer2Changed();
    }
    m_currentPlayer1 = addPlayer(name1);
    emit currentPlayer1Changed();
    saveToFile("players.txt");
    qDebug() << "name1 is " << m_currentPlayer1->looses() << " and name 2 is " << name2;

}

void PlayerController::update(int player, bool vsBot)
{
    if(player == 1){
        m_currentPlayer1->increaseWins();
        if(!vsBot) {
            m_currentPlayer2->increaseLooses();
        }
    }
    else if(player < 0){
        m_currentPlayer1->increaseLooses();
        if(player == -1){
            m_currentPlayer2->increaseWins();
        }
    }
    else if(player == 0){
        m_currentPlayer1->increaseDraws();

        if(!vsBot)
            m_currentPlayer2->increaseDraws();
    }
    emit playersChanged();
    saveToFile("players.txt");

}

void PlayerController::resetPlayer()
{
    m_currentPlayer1 = m_temp;
    m_currentPlayer2 = m_temp;
}
