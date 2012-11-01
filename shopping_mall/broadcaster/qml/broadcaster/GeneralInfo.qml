// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import QtDesktop 0.1

Rectangle {
    id: generalInfo

    Text {
        id: title
        font.pointSize: 20
        text: qsTr("General Information")
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }

    ListModel {
        id: generalInfoModel
        ListElement {
            info: "We inform to our clients that the mall will close in 15 minutes. Thank you."
        }
        ListElement {
            info: "Dear customers, in case of some emergency call number 5555."
        }
        ListElement {
            info: "We inform to our clients that the mall will close in 15 minutes. Thank you."
        }
        ListElement {
            info: "Dear customers, in case of some emergency call number 5555."
        }
        ListElement {
            info: "We inform to our clients that the mall will close in 15 minutes. Thank you."
        }
        ListElement {
            info: "Dear customers, in case of some emergency call number 5555."
        }
    }

    ListView {
        clip: true
        anchors.top: title.bottom
        anchors.left: parent.left
        anchors.right: parent.right
        anchors.bottom: backButton.top
        model: generalInfoModel
        delegate: Text {
            height: 50
            anchors.left: parent.left
            anchors.leftMargin: 10
            anchors.right: parent.right
            anchors.rightMargin: 10
            wrapMode: Text.WordWrap
            verticalAlignment: Text.AlignVCenter

            text: info

            Rectangle {
                color: "black"
                height: 1
                anchors.left: parent.left
                anchors.right: parent.right
                anchors.bottom: parent.bottom
            }

            MouseArea {
                anchors.fill: parent
                onClicked: { console.log(index) }
            }
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
        onClicked: generalInfo.opacity = 0
    }
}
