import QtQuick 2.15

Rectangle {
    id: rect
    property string textButton
    property int wButton: 120
    property int hButton: 70
    property string colorText: "black"
    property string colorButton: "transparent"
    property string colorButtonConvert
    property string colorBorder: "slategray"
    property int sizeText: 13
    property bool hover: false
    property int radiusButton: 15

    signal clickButton()
    width: wButton
    height: hButton

    color: colorButton
    border.color: colorBorder
    border.width: 3
    radius: radiusButton


    Text{
        text: textButton
        anchors.centerIn: parent
        color: colorText
        font.pointSize: sizeText
    }
    MouseArea{
        anchors.fill: parent
        onClicked: {
            clickButton();
        }
        hoverEnabled: hover
        onEntered: ColorAnimation {
            target: rect
            property: "color"
            to: colorButtonConvert
        }
        onExited: ColorAnimation {
            // from: "white"
            target: rect
            property: "color"
            to: colorButton
        }

    }

}
