// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import QtDesktop 0.1

Rectangle {
    id: foodCourt

    Text {
        id: title
        font.pointSize: 20
        text: qsTr("Food court")
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        id: orderNumber
        font.pointSize: 16
        text: qsTr("Current order number:")
        anchors.top: title.bottom
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        id: body
        font.pointSize: 50
        text: observer.order
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.WordWrap
        anchors.margins: 20
        anchors.top: orderNumber.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: restaurantsCombobox.top
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
        anchors.leftMargin: 10
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.bottom: backButton.top
        anchors.bottomMargin: 70

        onSelectedIndexChanged: { console.log(selectedText + ", " + selectedIndex);
            observer.restID = selectedIndex;
        }
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
        onClicked: foodCourt.opacity = 0
    }
}
