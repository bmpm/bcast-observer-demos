// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import QtDesktop 0.1

Rectangle {
    id: foodCourt

    signal clicked(int restaurant, string number)

    Text {
        id: title
        font.pointSize: 20
        text: qsTr("Food court")
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        id: restaurantLabel
        font.pointSize: 15
        text: qsTr("Restaurant:")
        anchors.top: title.bottom
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20
    }

    ListModel {
        id: restaurantsModel
        ListElement { text: "Restaurant1" }
        ListElement { text: "Restaurant2" }
        ListElement { text: "Restaurant3" }
        ListElement { text: "Restaurant4" }
    }

    ComboBox {
        id: restaurantsCombobox
        height: 40
        model: restaurantsModel
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.top: restaurantLabel.bottom
        anchors.topMargin: 20
    }

    Text {
        id: numberLabel
        font.pointSize: 15
        text: qsTr("Number:")
        anchors.top: restaurantsCombobox.bottom
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20
    }

    ListModel {
        id: numbersModel
        ListElement { text: "1001" }
        ListElement { text: "1002" }
        ListElement { text: "1003" }
        ListElement { text: "1004" }
        ListElement { text: "1005" }
        ListElement { text: "1006" }
        ListElement { text: "1007" }
        ListElement { text: "1008" }
    }

    ComboBox {
        id: numberCombobox
        height: 40
        model: numbersModel
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.top: numberLabel.bottom
        anchors.topMargin: 20
    }

    Button {
        id: submitButton
        width: 130
        height: 50
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        text: "Announce"
        onClicked: foodCourt.clicked(restaurantsCombobox.selectedIndex, numberCombobox.selectedText)
    }

    Button {
        id: backButton
        width: 50
        height: 50
        anchors.left: parent.left
        anchors.leftMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        text: "Back"
        onClicked: {
            foodCourt.visible = false
            mainScr.visible = true
        }
    }
}
