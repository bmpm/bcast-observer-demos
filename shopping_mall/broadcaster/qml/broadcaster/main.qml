// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import QtDesktop 0.1

Rectangle {
    width: 500
    height: 500

    Column {
        anchors.fill: parent
        anchors.topMargin: 30
        spacing: 30

        Button {
            id: generalInfoButton
            width: 200
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
            text: "General Info"
            onClicked: generalInfo.opacity = 1
        }

        Button {
            id: specialOfferButton
            width: 200
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Special offers"
            onClicked: specialOffer.opacity = 1
        }

        Button {
            id: foodCourtButton
            width: 200
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Food court"
            onClicked: foodCourt.opacity = 1
        }
    }

    GeneralInfo {
        id: generalInfo
        opacity: 0
        anchors.fill: parent
    }

    SpecialOffer {
        id: specialOffer
        opacity: 0
        anchors.fill: parent
    }

    FoodCourt {
        id: foodCourt
        opacity: 0
        anchors.fill: parent
    }
}
