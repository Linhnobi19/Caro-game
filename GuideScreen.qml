import QtQuick 2.15

Item {

    id: root
    Image {
        id: guildBackground
        source: "qrc:Image/guide.png"
        anchors.top: parent.top

        width: parent.width
        height: parent.height
        fillMode: Image.PreserveAspectCrop

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
                font.pointSize: 20
            }
        }

        Column{
            id: textGuide
            width: parent.width / 3
            height: parent.height
            spacing: 10
            anchors.top: titleGame.bottom
            anchors.topMargin: 20
            anchors.horizontalCenter: titleGame.horizontalCenter
            Text{
                text: "1. The size of Board is 10 x 10"
                color: "blue"
                font.pointSize: 13
                font.italic: true
            }

            Text{
                text: "2. You will pick X or O to enter into the board. O will go first"
                color: "blue"
                font.pointSize: 13
                font.italic: true
            }

            Text{
                text: "3. You will enter the position you want to pick (x y)"
                color: "blue"
                font.pointSize: 13
                font.italic: true
            }

            Text{
                text: "4. Cannot pick the position occuppied"
                color: "blue"
                font.pointSize: 13
                font.italic: true
            }

            Text{
                text: "5. The winner is the person who has 4 moves in a row horizontally, vertically or diagonall"
                color: "blue"
                font.pointSize: 13
                font.italic: true
            }

            Text{
                text: "6. The game will over when all of positions are filled and no one has won."
                color: "blue"
                font.pointSize: 13
                font.italic: true
            }
        }

        // Rectangle{
        //     width: parent.width - 100
        //     height: parent.height - titleGame.height - 20
        //     color: "transparent"
        //     border.color: "blue"
        //     border.width: 2
        //     anchors.top: titleGame.bottom
        //     anchors.horizontalCenter: parent.horizontalCenter

        // }

    }


}
