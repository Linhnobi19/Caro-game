#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Board.h"
#include "PlayerController.h"

#include <QObject>

class GameController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(Board* board READ board WRITE setBoard NOTIFY boardChanged FINAL)
    Q_PROPERTY(PlayerController* playerController READ playerController WRITE setPlayerController NOTIFY playerControllerChanged FINAL)

public:
    explicit GameController(QObject *parent = nullptr);
    ~GameController();

    Board *board() const;
    void setBoard(Board *newBoard);

    PlayerController *playerController() const;
    void setPlayerController(PlayerController *newPlayerController);

signals:
    void boardChanged();
    void playerControllerChanged();

private:
    Board *m_board = nullptr;
    PlayerController *m_playerController = nullptr;
};

#endif // GAMECONTROLLER_H
