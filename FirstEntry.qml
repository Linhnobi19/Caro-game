import QtQuick 2.15
import QtQuick.Controls 2.15

Column{
    id: containsFirstEntry
    width: 500
    height: 300
    spacing: 30

    property bool playBot: false
    property string validInput
    signal entryGame(inCase : bool);

    Rectangle{
        id: titleGame
        width: parent.width
        height: 120
        color: "transparent"

        Text{
            id: welcomeText
            text: "Welcome to Caro Game"
            font.pointSize: 40
            anchors.horizontalCenter: parent.horizontalCenter
            color: "red"
        }

        SequentialAnimation{
            loops: Animation.Infinite
            running: true
            NumberAnimation {
                target: welcomeText
                from: -10
                to: 10
                property: "rotation"
                duration: 1000
                easing.type: Easing.OutInQuad
            }

            NumberAnimation{
                target: welcomeText
                from: 10
                to: -10
                property: "rotation"
                duration: 1000
                easing.type: Easing.InOutQuad
            }

        }


        // Hiệu ứng đổi màu
        SequentialAnimation {
            loops: Animation.Infinite
            running: true
            ColorAnimation {
                target: welcomeText
                property: "color"
                from: "red"
                to: "blue"
                duration: 1000
            }
            ColorAnimation {
                target: welcomeText
                property: "color"
                from: "blue"
                to: "green"
                duration: 1000
            }
            ColorAnimation {
                target: welcomeText
                property: "color"
                from: "green"
                to: "yellow"
                duration: 1000
            }
            ColorAnimation {
                target: welcomeText
                property: "color"
                from: "yellow"
                to: "red"
                duration: 1000
            }
        }
    }

    Row{
        id: firstPlayerRow
        width: parent.width
        height: 60
        Rectangle{
            id: nameTitle
            width: parent.width / 3
            height: parent.height
            color: "transparent"
            Text {
                text: qsTr("First Player:")
                anchors.verticalCenter: parent.verticalCenter
                font.pointSize: 13
                font.bold: true
            }
        }
        Rectangle{
            width: parent.width - nameTitle.width
            height: parent.height
            color: "transparent"
            border.color: "dodgerblue"
            border.width: 4
            radius: 20
            TextInput{
                id: inputFirstName
                anchors.fill: parent
                clip: true
                verticalAlignment: Text.AlignVCenter
                font.pointSize: 13
                leftPadding: 20
            }
        }
    }

    Row{
        id: secondPlayerRow
        width: parent.width
        height: 120
        Rectangle{
            id: name2Title
            width: parent.width / 3
            height: parent.height
            color: "transparent"
            Text {
                text: qsTr("Second Player:")
                font.bold: true
                anchors.top: parent.top
                // anchors.horizontalCenter: parent.horizontalCenter
                anchors.topMargin: 10
                font.pointSize: 13
            }
        }
        Column{
            id: choicePlayer2
            width: parent.width - name2Title.width
            height: parent.height
            CheckBox{
                width: parent.width
                height: parent.height / 2
                checked: containsFirstEntry.playBot
                text: "is Bot"
                font.pointSize: 13

                onCheckedChanged: {
                    containsFirstEntry.playBot = checked;
                    if(checked){
                        borderInput.state = "lock";
                    }
                    else{
                        borderInput.state = "open";
                    }

                    console.log(containsFirstEntry.playBot);
                }
            }


            Rectangle{
                id: borderInput
                width: parent.width
                height: parent.height / 2
                color: "transparent"
                border.color: "dodgerblue"
                border.width: 4
                radius: 20
                TextInput{
                    id: inputSecondName
                    anchors.fill: parent
                    clip: true
                    verticalAlignment: Text.AlignVCenter
                    font.pointSize: 13
                    leftPadding: 20
                    readOnly: containsFirstEntry.playBot == true ? true : false
                }

                states: [
                    State {
                        name: "lock"
                        PropertyChanges {
                            target: borderInput
                            border.color: "gray"
                            // from: "lightslategrey"
                            // to: "red"
                        }
                    },
                    State {
                        name: "open"
                        PropertyChanges {
                            target: borderInput
                            // from: "red"
                            border.color: "dodgerblue"
                        }
                    }

                ]
            }
        }


    }


    Rectangle{
        id: submitContainer
        width: 150
        height: 60
        color: "darkturquoise"
        border.color: "black"
        border.width: 3
        radius: 20


        Text {
            id: submitText
            text: qsTr("Submit")
            anchors.centerIn: parent
            font.pointSize: 15
            color: "white"
            font.bold: true
        }
        MouseArea{
            anchors.fill: parent
            onClicked: {
                if(playBot){
                    validInput = game.playerController.checkPlayer(inputFirstName.text);
                }
                else{
                    validInput = game.playerController.checkPlayer(inputFirstName.text, inputSecondName.text);
                }

                if(validInput == "Success"){
                    if(playBot){
                        game.playerController.setCurrentPlayer(inputFirstName.text);
                    }
                    else{
                        game.playerController.setCurrentPlayer(inputFirstName.text, inputSecondName.text);
                    }
                    entryGame(playBot);
                    inputFirstName.text = ""
                    inputSecondName.text = ""
                }
                else{
                    blinkAni.start();
                }

            }

            onPressed: {
                parent.color = "dodgerblue"
            }
            onReleased: {
                parent.color = "darkturquoise"
            }
        }
    }


    // notification text
    Rectangle{
        id: invalidText
        width: 200
        height: 200
        color: "transparent"
        opacity: 0
        Text{
            id: blinkText
            // text: "Invalid input name.\nNickname can not contains space, must contains data and maximun is 32 chracters"
            text: validInput
            font.pointSize: 18
            color: "red"
            anchors.centerIn: parent
        }
        anchors.horizontalCenter: parent.horizontalCenter
    }
    // animation for blink the invalid text
    SequentialAnimation{
        id: blinkAni
        running: false
        loops: 3

        OpacityAnimator {
            id: fadeIn
            target: invalidText
            from: 0.0
            to: 1.0
            duration: 500
        }

        OpacityAnimator {
            id: fadeOut
            target: invalidText
            from: 1.0
            to: 0.0
            duration: 500
        }

    }


}
