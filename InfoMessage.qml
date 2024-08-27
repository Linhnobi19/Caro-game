import QtQuick 2.15

Item {
    anchors.top: parent.top
    anchors.topMargin: 20
    property int playerWin: 4
    // property bool winning

    onPlayerWinChanged: {
        if(playerWin == 1){
            playerWinId.text = game.playerController.currentPlayer1.nickName + " WIN";
        }
        if(playerWin == -2){
            playerWinId.text = "BOT WIN";
        }
        else if(playerWin == -1) {
            playerWinId.text = game.playerController.currentPlayer2.nickName + " WIN";
        }
    }

    signal comeback();
    signal replayGame();

    Rectangle{
        id: titleGame
        width: parent.width
        height: parent.height / 8
        color: "Transparent"
        Text {
            text: qsTr("Caro")
            anchors.centerIn: parent
            font.bold: true
            color: "red"
            font.pointSize: 40
        }
    }

    Rectangle{
        width: parent.width - 100
        height: parent.height - titleGame.height - 20
        color: "transparent"
        anchors.top: titleGame.bottom
        anchors.horizontalCenter: parent.horizontalCenter

        AnimatedImage{
            id: winningGif
            source: {
                if(playerWin == -2 || playerWin == 0){
                    return "qrc:Image/giphy.gif"
                }
                else return "qrc:Image/icegif.gif"
            }
            anchors.left: parent.left
            anchors.verticalCenter: parent.verticalCenter
        }

        Text{
            id: playerWinId
            text: "DRAW GAME"
            font.pointSize: 40
            anchors.centerIn: parent
            color: playerWin == 1 ? "blue" : (playerWin == 0 ? "black" : "red")
        }

        Row{
            id: notification
            spacing: 20
            anchors.top: playerWinId.bottom
            anchors.topMargin: 30
            anchors.horizontalCenter: playerWinId.horizontalCenter
            MyButton{
                textButton: "Replay"
                wButton: 300
                hButton: 120
                radiusButton: 25
                colorText: "White"
                colorButton: "skyblue"
                sizeText: 20
                hover: true
                colorButtonConvert: "dodgerblue"
                onClickButton: {
                    replayGame();
                }

            }
            MyButton{
                textButton: "Quit Match"
                wButton: 300
                hButton: 120
                radius: 25
                colorText: "White"
                colorButton: "skyblue"
                sizeText: 20
                hover: true
                colorButtonConvert: "dodgerblue"
                onClickButton: {
                    comeback();
                }
            }
        }

        AnimatedImage{
            id: winningGif2
            source: "qrc:Image/icegif-137.gif"
            anchors.right: parent.right
            anchors.verticalCenter: parent.verticalCenter
        }
    }
}
