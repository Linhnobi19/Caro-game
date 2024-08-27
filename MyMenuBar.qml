import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    // property for tabbar
    property int exceedWidth: 20
    property string focusColor: "#378CE7"
    property string backgroundColor: "#B0C5A4"
    property int fontSize: 13
    property string gameMode: "Easy"
    property int widthBar
    property bool isRunning: false
    property string menubarColor: "#B5C0D0"

    signal guideSignal();
    signal historySignal();
    signal goToEntrySignal();

    width: widthBar
    height: menuBar.contentHeight

    MenuBar {
        id: menuBar
        font.pointSize: 15
        width: widthBar
        height: contentHeight
        font.family: "Trebuchet MS"

        Menu {
            title: qsTr("File")
            background: Rectangle{
                implicitWidth: 200
                // implicitHeight: 100
                color: menubarColor
                radius: 10
            }

            MenuItem{
                text: "Go to Entry"
                font.pointSize: fontSize
                onTriggered: {
                    goToEntrySignal();
                }
            }
            MenuItem{
                text: "Exit"
                font.pointSize: fontSize
                onTriggered: {
                    Qt.quit();
                }
            }

        }
        Menu {
            id: menuMode
            title: qsTr("| Game Mode")
            enabled: isRunning == false ? true : false

            background: Rectangle{
                implicitWidth: 200
                // implicitHeight: 100
                color: menubarColor
                radius: 10
            }

            Column{
                anchors.left: parent.left
                anchors.leftMargin: 20
                spacing: 10
                RadioButton{
                    id: easyMode
                    text: "Easy"
                    checked: gameMode == text ? true : false
                    onClicked: {
                        gameMode = text
                        menuMode.close();
                    }
                }
                RadioButton{
                    id: normalMode
                    text: "Normal"
                    checked: gameMode == text ? true : false
                    onClicked: {
                        gameMode = text
                        menuMode.close();
                    }
                }
                RadioButton{
                    id: hardMode
                    text: "Hard"
                    checked: gameMode == text ? true : false
                    onClicked: {
                        gameMode = text
                        menuMode.close();
                    }
                }

            }
        }
        Menu {
            title: qsTr("| Game History")

            background: Rectangle{
                implicitWidth: 200
                // implicitHeight: 100
                color: menubarColor
                radius: 10
            }

            MenuItem{
                text: "History"
                font.pointSize: fontSize
                onTriggered: {
                    historySignal();
                }
            }
        }


        Menu {
            title: qsTr("| Guide document")
            background: Rectangle{
                implicitWidth: 200
                // implicitHeight: 100
                color: menubarColor
                radius: 10
            }
            MenuItem{
                text: "Guide"
                font.pointSize: fontSize
                onTriggered: {
                    guideSignal();
                }
            }
        }

        delegate: MenuBarItem {
            id: menuBarItem

            contentItem: Text {
                text: menuBarItem.text
                font: menuBarItem.font
                opacity: enabled ? 1.0 : 0.3
                color: menuBarItem.highlighted ? "#ffffff" : "black"
                horizontalAlignment: Text.AlignLeft
                verticalAlignment: Text.AlignVCenter
                elide: Text.ElideRight
            }

            background: Rectangle {
                implicitWidth: 40
                implicitHeight: 40
                radius: 15
                opacity: enabled ? 1 : 0.3
                color: menuBarItem.highlighted ? focusColor : "transparent"
            }
        }

        background: Rectangle {
            color: backgroundColor

            Rectangle {
                color: "dimgray"
                width: parent.width
                height: 1
                anchors.bottom: parent.bottom
            }
        }
    }
}
