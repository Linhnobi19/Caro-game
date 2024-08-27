#include "GameController.h"

GameController::GameController(QObject *parent)
    : QObject{parent}, m_board(new Board()), m_playerController(new PlayerController())
{}

GameController::~GameController()
{
    if(m_board != nullptr){
        delete m_board;
    }
    if(m_playerController != nullptr){
        delete m_playerController;
    }
}

Board *GameController::board() const
{
    return m_board;
}

void GameController::setBoard(Board *newBoard)
{
    if (m_board == newBoard)
        return;
    m_board = newBoard;
    emit boardChanged();
}

PlayerController *GameController::playerController() const
{
    return m_playerController;
}

void GameController::setPlayerController(PlayerController *newPlayerController)
{
    if (m_playerController == newPlayerController)
        return;
    m_playerController = newPlayerController;
    emit playerControllerChanged();
}
