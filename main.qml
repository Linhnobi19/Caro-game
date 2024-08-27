import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.15

Window {
    id: window
    width: 1800
    height: 920
    visible: true
    title: "Caro game"
    // visibility: "FullScreen"
    property bool gameStarted: false
    property bool bot: false
    property bool isInInfo: false

    onGameStartedChanged: {
        // for lock choosing mode in game
        menuBarOptions.isRunning = gameStarted
    }


    onBotChanged: {
        playGameId.playVBot = bot
    }

    MyMenuBar{
        id: menuBarOptions
        widthBar: parent.width
        anchors.top: parent.top

        onGameModeChanged: {
            playGameId.gameMode = gameMode
        }

        onHistorySignal: {
            mainScreen.state = "searchInfo"
        }
        onGuideSignal: {
            mainScreen.state = "guideScreen"
        }
        onGoToEntrySignal: {
            if(!gameStarted){
                if(isInInfo){
                    mainScreen.state = "infoMessage";
                }
                else {
                    mainScreen.state = "firstEntry";
                }
            }
            else{
                mainScreen.state = "playGame";
            }
        }
    }

    Rectangle{
        id: mainScreen
        width: parent.width
        height: (parent.height - menuBarOptions.height)
        color: menuBarOptions.backgroundColor
        anchors.top: menuBarOptions.bottom
        Image {
            id: backgroundImage
            width: parent.width
            height: parent.height
            source: "qrc:/Image/back2.jpg"
            fillMode: Image.PreserveAspectCrop
        }

        FirstEntry{
            id: firstEntryId
            anchors.centerIn: parent
            visible: true
            onEntryGame: {
                window.bot = inCase
                game.board.resetBoard();
                mainScreen.state = "playGame"
                console.log(playBot);
                gameStarted = true;
                playGameId.character = "O"
                playGameId.number = 1;
                playGameId.isReplay = false;
                playGameId.runningCount = true;
                playGameId.countTime = 0;
                playGameId.isPlayer1 = true;
            }
        }


        PlayGame{
            id: playGameId
            wScreen: parent.width
            hScreen: parent.height
            colorBackground: menuBarOptions.backgroundColor
            visible: false

            Timer{
                id: stopBeforeTrans
                repeat: false;
                interval: 3000
                onTriggered: {
                    game.board.resetBoard();
                    // set endgame here because still need a little time to wait
                    // if set on signal gameEnd --> player still get move on board
                    playGameId.endGame = false;
                    mainScreen.state = "infoMessage";
                    window.isInInfo = true;
                }
            }

            onGameEnd: {
                infoMessageId.playerWin = player
                stopBeforeTrans.start();
                gameStarted = false;
            }

            onReplayEnd: {
                mainScreen.state = "infoMessage";
            }
        }

        InfoMessage{
            id: infoMessageId
            width: parent.width
            height: parent.height - 10
            visible: false
            onComeback: {
                mainScreen.state = "firstEntry"
                game.playerController.resetPlayer();
                game.board.clearReplay();
                window.bot = false;
                window.isInInfo = false;
            }
            onReplayGame: {
                mainScreen.state = "playGame"
                playGameId.character = "O";
                playGameId.number = 1;
                playGameId.isReplay = true;
            }
        }


        SearchInfo{
            id: searchInfoId
            width: parent.width
            height: parent.height
            visible: false

        }


        GuideScreen{
            id: guideScreenId
            width: parent.width
            height: parent.height
            visible: false
        }


        states: [
            State{
                name: "firstEntry"
                PropertyChanges {
                    target: firstEntryId
                    visible: true
                    opacity: 1
                }
                PropertyChanges {
                    target: playGameId
                    visible: false
                    opacity: 0
                }
                PropertyChanges {
                    target: searchInfoId
                    visible: false
                    opacity: 0
                }
                PropertyChanges {
                    target: guideScreenId
                    visible: false
                    opacity: 0
                }
                PropertyChanges {
                    target: infoMessageId
                    visible: false
                    opacity: 0
                }
            },
            State{
                name: "playGame"
                PropertyChanges {
                    target: firstEntryId
                    visible: false
                    opacity: 0
                }
                PropertyChanges {
                    target: playGameId
                    visible: true
                    opacity: 1
                }
                PropertyChanges {
                    target: searchInfoId
                    visible: false
                    opacity: 0
                }
                PropertyChanges {
                    target: guideScreenId
                    visible: false
                    opacity: 0
                }
                PropertyChanges {
                    target: infoMessageId
                    visible: false
                    opacity: 0
                }
            },
            State{
                name: "searchInfo"
                PropertyChanges {
                    target: firstEntryId
                    visible: false
                    opacity: 0
                }
                PropertyChanges {
                    target: playGameId
                    visible: false
                    opacity: 0
                }
                PropertyChanges {
                    target: searchInfoId
                    visible: true
                    opacity: 1
                }
                PropertyChanges {
                    target: guideScreenId
                    visible: false
                    opacity: 0
                }
                PropertyChanges {
                    target: infoMessageId
                    visible: false
                    opacity: 0
                }
            },
            State{
                name: "guideScreen"
                PropertyChanges {
                    target: firstEntryId
                    visible: false
                    opacity: 0
                }
                PropertyChanges {
                    target: playGameId
                    visible: false
                    opacity: 0
                }
                PropertyChanges {
                    target: searchInfoId
                    visible: false
                    opacity: 0
                }
                PropertyChanges {
                    target: guideScreenId
                    visible: true
                    opacity: 1
                }
                PropertyChanges {
                    target: infoMessageId
                    visible: false
                    opacity: 0
                }
            },
            State{
                name: "infoMessage"
                PropertyChanges {
                    target: firstEntryId
                    visible: false
                    opacity: 0
                }
                PropertyChanges {
                    target: playGameId
                    visible: false
                    opacity: 0
                }
                PropertyChanges {
                    target: searchInfoId
                    visible: false
                    opacity: 0
                }
                PropertyChanges {
                    target: guideScreenId
                    visible: false
                    opacity: 0
                }
                PropertyChanges {
                    target: infoMessageId
                    visible: true
                    opacity: 1
                }
            }

        ]

        transitions: Transition {
            from: "*"
            to: "*"
            reversible: true
            SequentialAnimation{
                NumberAnimation {
                    properties: "opacity"
                    duration: 500
                }
                PropertyAnimation{
                    properties: "visible"
                    duration: 100
                }
            }

        }

    }

}






