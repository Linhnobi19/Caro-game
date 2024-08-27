#ifndef PLAYERCONTROLLER_H
#define PLAYERCONTROLLER_H

#include <QObject>
#include <QList>
#include <QHash>
#include <QVariantList>
#include "Player.h"

class PlayerController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QList<Player*> players READ players WRITE setPlayers NOTIFY playersChanged FINAL)
    Q_PROPERTY(Player* currentPlayer1 READ currentPlayer1 WRITE setCurrentPlayer1 NOTIFY currentPlayer1Changed FINAL)
    Q_PROPERTY(Player* currentPlayer2 READ currentPlayer2 WRITE setCurrentPlayer2 NOTIFY currentPlayer2Changed FINAL)
public:
    explicit PlayerController(QObject *parent = nullptr);
    ~PlayerController();

    Player* addPlayer(QString& name);

    void getFromFile(const QString& path);
    void saveToFile(const QString& path);

    QList<Player *> players() const;
    void setPlayers(const QList<Player *> &newPlayers);

    Q_INVOKABLE QList<Player*> search(const QString& name);
    Q_INVOKABLE QList<Player*> searchRank(int rank,const QString& name);

    Q_INVOKABLE QString checkPlayer(const QString name1, const QString name2 = "BOT");

    Player *currentPlayer1() const;
    void setCurrentPlayer1(Player *newCurrentPlayer1);

    Player *currentPlayer2() const;
    void setCurrentPlayer2(Player *newCurrrentPlayer2);

    Q_INVOKABLE void setCurrentPlayer(QString name1, QString name2 = "BOT");
    Q_INVOKABLE void update(int player, bool vsBot);
    Q_INVOKABLE void resetPlayer();

signals:
    void playersChanged();
    void currentPlayer1Changed();

    void currentPlayer2Changed();

private:
    QList<Player *> m_players;
    QHash<QString, bool> nameExisted;
    Player *m_currentPlayer1 = nullptr;
    Player *m_currentPlayer2 = nullptr;
    Player* m_temp;
};

#endif // PLAYERCONTROLLER_H
