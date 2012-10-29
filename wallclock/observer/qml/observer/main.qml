// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import QtDesktop 0.1

Rectangle {
    id: main
    width: 360
    height: 360

    Text {
        id: title
        font.pointSize: 20
        text: qsTr("Current time")
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        id: time
        font.pointSize: 26
        text: observer.hour + ":" + observer.minute + ":" + observer.second
        anchors.centerIn: parent
    }
}
