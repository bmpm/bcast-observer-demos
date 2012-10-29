// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import com.indt.components 1.0

Rectangle {
    WallClockSetter {
        id: setter
    }

    width: 360
    height: 360
    Text {
        text: qsTr("Hello World")
        anchors.centerIn: parent
    }
    MouseArea {
        anchors.fill: parent
        onClicked: {
            setter.setTime(0, 0, 0);
            //Qt.quit();
        }
    }
}
