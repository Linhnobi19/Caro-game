#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include <QString>

enum Ranking {
    Beginner,
    Intermidiate,
    Advanced,
    Expert
};

class Player : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString nickName READ nickName WRITE setNickName NOTIFY nickNameChanged FINAL)
    Q_PROPERTY(int wins READ wins WRITE setWins NOTIFY winsChanged FINAL)
    Q_PROPERTY(int draws READ draws WRITE setDraws NOTIFY drawsChanged FINAL)
    Q_PROPERTY(int looses READ looses WRITE setLooses NOTIFY loosesChanged FINAL)
    Q_PROPERTY(Ranking rank READ rank WRITE setRank NOTIFY rankChanged FINAL)
public:
    explicit Player(QObject *parent = nullptr);
    Player(QString n, int w, int d, int l, QObject* parent = nullptr);

    QString nickName() const;
    void setNickName(const QString &newNickName);

    int wins() const;
    void setWins(int newWins);

    int draws() const;
    void setDraws(int newDraws);

    int looses() const;
    void setLooses(int newLooses);

    Ranking rank() const;
    void setRank(Ranking newRank);
    void updateRank();

    void increaseWins();
    void increaseDraws();
    void increaseLooses();

signals:
    void nickNameChanged();
    void winsChanged();

    void drawsChanged();

    void loosesChanged();

    void rankChanged();

private:
    QString m_nickName;
    int m_wins;
    int m_draws;
    int m_looses;
    Ranking m_rank;
};

#endif // PLAYER_H
