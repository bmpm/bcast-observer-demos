// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import QtDesktop 0.1

Rectangle {
    id: specialOffer

    ListModel {
        id: productsOBSModel
        ListElement { text: "Product1" }
        ListElement { text: "Product2" }
        ListElement { text: "Product3" }
        ListElement { text: "Product4" }
    }

    ListModel {
        id: storesOBSModel
        ListElement { text: "Sports" }
        ListElement { text: "Drugstore" }
        ListElement { text: "Cinema" }
        ListElement { text: "Computers" }
    }

    Text {
        id: title
        font.pointSize: 20
        text: qsTr("Special offers")
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        id: body
        font.pointSize: 16
        text: qsTr("The store " + storesOBSModel.get(observer.store).text +
                   " has an incredible discount for you: " + productsOBSModel.get(observer.product).text +
                   " only $" + observer.price)
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.WordWrap
        anchors.margins: 20
        anchors.top: title.bottom
        anchors.topMargin: 60
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
        onClicked: specialOffer.opacity = 0
    }
}
