import QtQuick 2.15
import QtQuick.Controls 2.15


Item{

    id: root
    width: 1000
    height: 1000

    property string textSearch
    property string colorText: "#5755FE"

    onTextSearchChanged: {
        sameRank.model = game.playerController.searchRank(rankChoice.currentIndex, textSearch);
    }

    Rectangle{
        id: titleSearch
        width: parent.width
        height: 100
        anchors.top: parent.top
        anchors.topMargin: 30
        anchors.left: parent.left
        anchors.leftMargin: 40

        color: "transparent"

        Row{
            spacing: 20
            Text{
                id: title
                text: "Player list"
                font.pointSize: 20
                font.bold: true
            }

            TextField{
                width: 500
                placeholderText: "Enter name player"
                font.pointSize: 14
                onTextChanged: {
                    if(text != ""){
                        searchResults.model = game.playerController.search(text)
                    }
                    else{
                        searchResults.model = [];
                    }
                    root.textSearch = text
                }
            }

        }
    }



    Rectangle{
        id: borderSearch
        width: parent.width - 20
        height: (parent.height - titleSearch.y)/2 - 100
        border.color: "black"
        border.width: 3
        anchors.top: titleSearch.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        color: "transparent"

        Text{
            id: noValue
            text: "No data search"
            font.pointSize: 20
            color: "red"
            anchors {
                left: parent.left
                top: parent.top
            }
            anchors.leftMargin: 20
            anchors.topMargin: 10
            visible: searchResults.count === 0 ? true : false
        }

        ListView{
            id: searchResults
            width: parent.width
            height: parent.height
            anchors.top: parent.top
            anchors.topMargin: 20
            displayMarginEnd: -50
            displayMarginBeginning: -50

            visible: count > 0 ? true : false

            delegate: Item {
                width: parent.width
                height: 50
                Row{
                    width: parent.width - 20
                    height: parent.height
                    leftPadding: 20
                    Text {
                        width: parent.width / 4
                        text: "Name: " + model.modelData.nickName
                        font.pointSize: 12
                        color: colorText
                    }
                    Text {
                        width: parent.width / 4
                        text: "Wins: " + model.modelData.wins
                        font.pointSize: 12
                        color: colorText
                    }

                    Text {
                        width: parent.width / 4
                        text:"Draws: " +  model.modelData.draws
                        font.pointSize: 12
                        color: colorText
                    }

                    Text {
                        width: parent.width / 4
                        text: "Loose: " + model.modelData.looses
                        font.pointSize: 12
                        color: colorText
                    }
                }
            }
        }
    }



    Rectangle{
        id: borderSameRank
        width: parent.width - 20
        height: parent.height - borderSearch.height - titleSearch.height - 60
        anchors.top: borderSearch.bottom
        anchors.topMargin: 20
        border.color: "black"
        border.width: 3
        color: "transparent"
        anchors.horizontalCenter: parent.horizontalCenter


        Text{
            id: headerSameRank
            text: "The same level"
            font.pointSize: 25
            font.bold: true
            leftPadding: 10
            topPadding: 10
        }


        Text{
            id: noValue2
            text: "No data search"
            font.pointSize: 20
            color: "red"
            anchors {
                left: parent.left
                top: parent.top
            }
            anchors.leftMargin: 10
            anchors.topMargin: headerSameRank.height + 10
            visible: sameRank.count === 0 ? true : false
        }

        ComboBox{
            id: rankChoice
            anchors.left: headerSameRank.right
            anchors.leftMargin: 30
            model: ["Beginner", "Intermidiate", "Advance", "Expert"]
            anchors.verticalCenter: headerSameRank.verticalCenter
            onCurrentIndexChanged:  {
                sameRank.model = game.playerController.searchRank(rankChoice.currentIndex, textSearch);
            }
        }


        ListView{
            id: sameRank
            width: parent.width - 20
            height: parent.height - headerSameRank.height- 20
            visible: count > 0 ? true : false
            anchors.top: headerSameRank.bottom
            anchors.topMargin: 10
            anchors.horizontalCenter: parent.horizontalCenter
            displayMarginBeginning: -50
            displayMarginEnd: -50
            delegate: Item {
                width: parent.width
                height: 50
                Row{
                    width: parent.width - 20
                    height: parent.height
                    leftPadding: 20
                    Text {
                        width: parent.width / 4
                        text: "Name: " + model.modelData.nickName
                        font.pointSize: 12
                        color: colorText
                    }
                    Text {
                        width: parent.width / 4
                        text: "Wins: " + model.modelData.wins
                        font.pointSize: 12
                        color: colorText
                    }

                    Text {
                        width: parent.width / 4
                        text:"Draws: " +  model.modelData.draws
                        font.pointSize: 12
                        color: colorText
                    }

                    Text {
                        width: parent.width / 4
                        text: "Loose: " + model.modelData.looses
                        font.pointSize: 12
                        color: colorText
                    }
                }
            }
        }
    }
}
