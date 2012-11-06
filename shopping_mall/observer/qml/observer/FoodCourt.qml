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
        anchors.bottom: backButton.top
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
