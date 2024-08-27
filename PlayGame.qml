import QtQuick 2.15
import QtQuick.Dialogs 1.3

Item {
    id: root
    property int wScreen
    property int hScreen
    property string colorBackground
    property bool endGame: false
    property bool playVBot: false
    property bool isReplay: false
    property bool runningCount: false
    property string timerPlayer1: "00:00"
    property string timerPlayer2: "00:00"
    property bool isPlayer1: true   // for switch timer to 2 player
    property string gameMode: "Easy"
    property int countTime: 0


    signal gameEnd(player : int);
    signal replayEnd();


    onGameEnd: {
        character = "O";
        number = 1;
    }

    onPlayVBotChanged: {
        if(playVBot){
            name2Info.text = "BOT"
            win2Info.text = ""
            draw2Info.text = ""
            loose2Info.text = ""
        }
        else {
            name2Info.text = game.playerController.currentPlayer2.nickName
            win2Info.text = "Wins: " + game.playerController.currentPlayer2.wins
            draw2Info.text = "Draws: " + game.playerController.currentPlayer2.draws
            loose2Info.text = "Looses: " + game.playerController.currentPlayer2.looses
        }
    }

    Timer {
        id: countTimer
        interval: 1000  // 1 giây
        repeat: true
        running: runningCount && !endGame
        onTriggered: {
            countTime += 1;
            if(isPlayer1){
                root.timerPlayer1 = root.formatTime(countTime);
            }
            else {
                root.timerPlayer2 = root.formatTime(countTime)
            }
        }
    }



    function formatTime(seconds) {
        var minutes = Math.floor(seconds / 60);
        var secs = seconds % 60;
        return ("0" + minutes).slice(-2) + ":" + ("0" + secs).slice(-2);
    }


    width: wScreen
    height: hScreen

    // title of the game
    Rectangle{
        id: titleGame
        width: parent.width
        height: parent.height / 8
        anchors.top: parent.top
        anchors.topMargin: 20
        color: "Transparent"
        Text {
            text: qsTr("Caro")
            anchors.centerIn: parent
            font.bold: true
            color: "red"
            font.pointSize: 20
        }
    }



    // info of player 1
    Rectangle{
        id: player1Container
        width: (parent.width - caroBoard.width) / 2
        height: parent.height
        color: "Transparent"
        // color: "red"


        Text {
            id: nameInfo
            text: game.playerController.currentPlayer1.nickName
            color: "blue"
            font.bold: true
            font.pointSize: 20
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 150
        }

        Text {
            id: winInfo
            text: "Wins: " + game.playerController.currentPlayer1.wins + ","
            font.bold: true
            color: "black"
            font.pointSize: 16
            anchors.top: nameInfo.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 20
        }

        Text {
            id: drawInfo
            text: "Draws: " + game.playerController.currentPlayer1.draws + ","
            font.bold: true
            color: "black"
            font.pointSize: 16
            anchors.top: winInfo.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 20
        }

        Text {
            id: looseInfo
            text:  "Losses: " + game.playerController.currentPlayer1.looses
            font.bold: true
            color: "black"
            font.pointSize: 16
            anchors.top: drawInfo.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 20
        }

        Text {
            id: time1Text
            anchors.top: looseInfo.bottom
            anchors.topMargin: 30
            visible: {
                if(!isReplay)
                    return isPlayer1 ? true : false;
                else
                    return false
            }
            text: root.timerPlayer1
            color: "blue"
            font.bold: true
            font.pointSize: 25
            anchors.horizontalCenter: parent.horizontalCenter
        }
    }

    property string character: "O"
    property int number: 1

    // grid view for board
    GridView{
        id: caroBoard
        width: 500
        height: 500
        cellWidth: width / game.board.boardSize
        cellHeight: height / game.board.boardSize
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: titleGame.bottom
        interactive: false
        model: game.board.boardData


        delegate: Rectangle{
            width: caroBoard.cellWidth
            height: caroBoard.cellHeight
            border.color: "black"
            border.width: 2
            color: "white"
            enabled: game.board.isBusy ? false : true
            property bool changeColor: false
            property bool isWinning: false
            property string colorText

            Text{
                id: cellId
                text: modelData.value
                font.pointSize: 12
                font.bold: true
                color: colorText
                anchors.centerIn: parent
            }

            SequentialAnimation on color{
                loops: Animation.Infinite
                running: changeColor
                ColorAnimation {
                    from: "white"
                    to: "yellow"
                    duration: 500
                }

                ColorAnimation {
                    from: "yellow"
                    to: "white"
                    duration: 500
                }

            }

            SequentialAnimation on color{
                loops: Animation.Infinite
                running: isWinning
                ColorAnimation {
                    from: "white"
                    to: "cyan"
                    duration: 500
                }

                ColorAnimation {
                    from: "cyan"
                    to: "white"
                    duration: 500
                }

            }


            function playVersusBot(){
                if(cellId.text == ""){
                    cellId.color = "blue"
                    endGame = game.board.makeMove(index, "O");
                    root.countTime = 0;
                    root.isPlayer1 = false;
                    root.timerPlayer1 = "00:00";
                    root.timerPlayer2 = "00:00";
                    if(!endGame) {
                        endGame = game.board.botMove(gameMode);
                        if(endGame){
                            gameEnd(-2);
                        }
                        else if (game.board.isFull()){
                            gameEnd(0);     // draw
                            game.playerController.update(0, root.playVBot);
                        }
                    }
                    else {
                        gameEnd(number);        // player win
                        game.playerController.update(number, root.playVBot);
                        console.log("reset board");
                    }

                }
            }
            function playVersusPlayer(){
                if(cellId.text == ""){
                    colorText = root.character == "O" ? "blue" : "red"
                    endGame = game.board.makeMove(index, character);
                    if(!endGame) {
                        if(game.board.isFull()){
                            gameEnd(0);     // draw game
                            game.playerController.update(0, root.playVBot);
                        }
                        else{
                            number = number == 1 ? -1 : 1
                            root.character = root.character == "X" ? "O" : "X"
                        }

                    }
                    else {
                        gameEnd(number);
                        game.playerController.update(number, root.playVBot);
                        console.log("reset board");
                    }

                }
            }

            MouseArea{
                anchors.fill: parent
                enabled: (isReplay || endGame) ? false : true
                onClicked: {
                    if(!playVBot){
                        parent.playVersusPlayer();
                        if(!endGame){
                            root.countTime = 0;
                            root.isPlayer1 = root.isPlayer1 ? false : true
                        }
                        else {
                            root.runningCount = false;
                        }
                        root.timerPlayer1 = "00:00";
                        root.timerPlayer2 = "00:00";
                    }
                    else{
                        parent.playVersusBot();
                    }

                }
            }
        }
    }


    // for changing color when win state was set
    property var newIndecies: []

    Timer{
        id: stopWinning
        repeat: false
        interval: 3000
        onTriggered: {
            for(let i = 0; i < newIndecies.length; i++){
                caroBoard.itemAtIndex(root.newIndecies[i]).isWinning = false;
            }
        }
    }

    // connect signal from board to check winning line
    Connections{
        target: game.board

        function onIsBusyChanged(){
            if(!game.board.isBusy){
                root.countTime = 0;
                root.isPlayer1 = root.isPlayer1 ? false : true
                root.timerPlayer1 = "00:00";
                root.timerPlayer2 = "00:00";
            }
        }

        function onBotMoveSuccessful(index){
            caroBoard.itemAtIndex(index).colorText = "red";
        }


        function onWinningState(indecies) {
            root.newIndecies = indecies.slice();
            for(let i = 0; i < caroBoard.count; i++){
                caroBoard.itemAtIndex(i).changeColor = false;
            }

            for(let i = 0; i < indecies.length; i++){
                caroBoard.itemAtIndex(indecies[i]).isWinning = true;
                stopWinning.start();
            }
        }

    }


    // info of player 2
    Rectangle{
        id: player2Container
        width: (parent.width - caroBoard.width) / 2
        height: parent.height
        color: "Transparent"
        anchors.right: parent.right
        // color: "red"


        Text {
            id: name2Info
            text: playVBot === false ? game.playerController.currentPlayer2.nickName : "BOT"
            color: "red"
            font.bold: true
            font.pointSize: 20
            anchors.top: parent.top
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 150
        }

        Text {
            id: win2Info
            text: playVBot === false ? "Wins: " + game.playerController.currentPlayer2.wins + "," : ""
            font.bold: true
            color: "black"
            font.pointSize: 16
            anchors.top: name2Info.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 20
        }

        Text {
            id: draw2Info
            text: playVBot === false ?  "Draws: " + game.playerController.currentPlayer2.draws + "," : ""
            font.bold: true
            color: "black"
            font.pointSize: 16
            anchors.top: win2Info.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 20
        }

        Text {
            id: loose2Info
            text: playVBot === false ? "Losses: " + game.playerController.currentPlayer2.looses : ""
            font.bold: true
            color: "black"
            font.pointSize: 16
            anchors.top: draw2Info.bottom
            anchors.horizontalCenter: parent.horizontalCenter
            anchors.topMargin: 20
        }

        Text {
            id: time2Text
            anchors.top: loose2Info.bottom
            anchors.topMargin: 30
            // visible: isPlayer1 ? false : true
            visible: {
                if(!isReplay)
                    return isPlayer1 ? false : true;
                else
                    return false
            }

            text: root.timerPlayer2
            color: "red"
            font.bold: true
            font.pointSize: 25
            anchors.horizontalCenter: parent.horizontalCenter
        }

    }

    // dialog for concede the game
    MessageDialog{
        id: warnMessage
        title: "Concede the game"
        text: "You will loose this game. Do you want to concede?"
        standardButtons: StandardButton.Yes | StandardButton.Cancel
        onYes:{
            if(playVBot){
                gameEnd(-2);
            }
            else {
                gameEnd(number == 1 ? -1 : 1)
            }
        }
        onRejected: {
            warnMessage.close()
        }
    }

    MessageDialog{
        id: quitMessage
        title: "Quit the game"
        text: "Do you want to quit and close the game?"
        standardButtons: StandardButton.Yes | StandardButton.Cancel
        onYes:{
            Qt.quit();
        }
        onRejected: {
            warnMessage.close();
        }
    }

    Rectangle{
        id: buttonContainer
        width: 460
        height: parent.height / 4
        color: "transparent"
        visible: isReplay ? false : true
        enabled: {
            if(game.board.isBusy){
                return false;
            }
            return endGame ? false : true
        }
        anchors.horizontalCenter: caroBoard.horizontalCenter
        anchors.top: caroBoard.bottom
        anchors.topMargin: 80


        Row{
            spacing: 50

            MyButton{
                id: concedeButton
                textButton: "Concede"
                onClickButton: {
                    warnMessage.open();
                }
            }

            MyButton{
                id: undoButton
                textButton: "Undo"
                onClickButton: {
                    game.board.undoInMatch(playVBot);
                    if(!playVBot){
                        root.isPlayer1 = root.isPlayer1 ? false : true
                        root.countTime = 0;
                        root.timerPlayer1 = "00:00"
                        root.timerPlayer2 = "00:00"
                    }
                }
            }

            MyButton{
                id: quitButton
                textButton: "Quit match"
                onClickButton: {
                    quitMessage.open();
                }
            }
        }
    }


    Rectangle{
        id: replayContainer
        width: 460
        height: parent.height / 4
        color: "transparent"
        visible: isReplay ? true : false

        anchors.horizontalCenter: caroBoard.horizontalCenter
        anchors.top: caroBoard.bottom
        anchors.topMargin: 80


        property int i: 0
        Timer{
            id: timer
            interval: 3000
            repeat: false
            onTriggered: {
                if(replayContainer.i >= 0){
                    caroBoard.itemAtIndex(replayContainer.i).changeColor = false;
                }
            }
        }

        Row{
            spacing: 50
            MyButton{
                id: nextMove
                textButton: "nextMove"
                onClickButton: {
                    replayContainer.i = game.board.redo();
                    for(let i = 0; i < game.board.boardSize * game.board.boardSize; i++){
                        caroBoard.itemAtIndex(i).changeColor = false;
                        caroBoard.itemAtIndex(i).color = "white";
                    }

                    caroBoard.itemAtIndex(replayContainer.i).changeColor = true;
                    timer.start();
                    // caroBoard.itemAtIndex(i).changeColor = false;

                }
            }

            MyButton{
                id: prevMove
                textButton: "prevMove"
                onClickButton: {
                    replayContainer.i = game.board.undo();
                    for(let i = 0; i < game.board.boardSize * game.board.boardSize; i++){
                        caroBoard.itemAtIndex(i).changeColor = false;
                        caroBoard.itemAtIndex(i).color = "white";
                    }
                    if(replayContainer.i >= 0){
                        caroBoard.itemAtIndex(replayContainer.i).changeColor = true;
                        timer.start();
                    }

                    // caroBoard.itemAtIndex(i).changeColor = false;
                }
            }

            MyButton{
                id: quitReplay
                textButton: "Quit match"
                onClickButton: {
                    replayEnd();
                }
            }
        }
    }


}



