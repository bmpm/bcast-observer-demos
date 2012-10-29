// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import QtDesktop 0.1
import com.indt.components 1.0

Rectangle {
    id: main
    width: 360
    height: 360

    WallClockSetter {
        id: setter
    }

    Text {
        id: title
        font.pointSize: 20
        text: qsTr("Current time")
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Item {
        width: 300
        height: 50
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: title.bottom
        anchors.topMargin: 20
        anchors.bottom: submitButton.top
        anchors.bottomMargin: 20

        Row {
            anchors.verticalCenter: parent.verticalCenter
            anchors.left: parent.left
            anchors.leftMargin: 20
            anchors.right: parent.right
            anchors.rightMargin: 20
            spacing: 8
            SpinBox {
                id: hour
                width: 70
                minimumValue: 0
                maximumValue: 23
                value: 0
                KeyNavigation.tab: minutes
                KeyNavigation.backtab: submitButton
            }

            Text {
                font.pointSize: 20
                text: qsTr(":")
                anchors.verticalCenter: hour.verticalCenter
            }

            SpinBox {
                id: minutes
                width: hour.width
                minimumValue: 0
                maximumValue: 59
                value: 0
                KeyNavigation.tab: seconds
                KeyNavigation.backtab: hour
            }

            Text {
                font.pointSize: 20
                text: qsTr(":")
                anchors.verticalCenter: hour.verticalCenter
            }

            SpinBox {
                id: seconds
                width: hour.width
                minimumValue: 0
                maximumValue: 59
                value: 0
                KeyNavigation.tab: submitButton
                KeyNavigation.backtab: minutes
            }
        }
    }

    Button {
        id: submitButton
        width: 150
        height: 50
        anchors.centerIn: parent
        text: "Update clients time"
        onClicked: setter.setTime(hour.value, minutes.value, seconds.value)
    }
}
