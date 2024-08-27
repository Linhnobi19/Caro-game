#include "Player.h"

Player::Player(QObject *parent)
    : QObject{parent}, m_nickName(""), m_wins(0)
    , m_draws(0), m_looses(0), m_rank(Ranking::Beginner)
{}

Player::Player(QString n, int w, int d, int l, QObject *parent)
    : QObject{parent}, m_nickName(n), m_wins(w)
    , m_draws(d), m_looses(l)
{
    updateRank();
}

QString Player::nickName() const
{
    return m_nickName;
}

void Player::setNickName(const QString &newNickName)
{
    if (m_nickName == newNickName)
        return;
    m_nickName = newNickName;
    emit nickNameChanged();
}

int Player::wins() const
{
    return m_wins;
}

void Player::setWins(int newWins)
{
    if (m_wins == newWins)
        return;
    m_wins = newWins;
    emit winsChanged();
}

int Player::draws() const
{
    return m_draws;
}

void Player::setDraws(int newDraws)
{
    if (m_draws == newDraws)
        return;
    m_draws = newDraws;
    emit drawsChanged();
}

int Player::looses() const
{
    return m_looses;
}

void Player::setLooses(int newLooses)
{
    if (m_looses == newLooses)
        return;
    m_looses = newLooses;
    emit loosesChanged();
}

Ranking Player::rank() const
{
    return m_rank;
}

void Player::setRank(Ranking newRank)
{
    if (m_rank == newRank)
        return;
    m_rank = newRank;
    emit rankChanged();
}

void Player::updateRank()
{
    int total = m_wins + m_draws + m_looses;
    double winRate = total > 0 ? static_cast<double>(m_wins) / total : 0;

    if (total < 10) {
        m_rank = Ranking::Beginner;
    }
    else if (winRate > 0.7 && total > 100) {
        m_rank = Ranking::Expert;
    }
    else if (winRate > 0.7 && total > 50) {
        m_rank = Ranking::Advanced;
    }
    else if (winRate > 0.7 && total > 10) {
        m_rank = Ranking::Intermidiate;
    }
    else if (winRate > 0.5 && total > 30) {
        m_rank = Ranking::Advanced;
    }
    else if (winRate > 0.5 && total > 10) {
        m_rank = Ranking::Intermidiate;
    }
    else if (winRate > 0.3) {
        m_rank = Ranking::Intermidiate;
    }
    else
    {
        m_rank = Ranking::Beginner;
    }
    emit rankChanged();
}

void Player::increaseWins()
{
    m_wins++;
    updateRank();
    emit winsChanged();
}

void Player::increaseDraws()
{
    m_draws++;
    updateRank();
    emit drawsChanged();
}

void Player::increaseLooses()
{
    m_looses++;
    updateRank();
    emit loosesChanged();
}
