// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import QtDesktop 0.1

Rectangle {
    id: specialOffer

    signal clicked(int store, int product, string price)

    Text {
        id: title
        font.pointSize: 20
        text: qsTr("Special offers")
        anchors.top: parent.top
        anchors.topMargin: 20
        anchors.horizontalCenter: parent.horizontalCenter
    }

    Text {
        id: storeLabel
        font.pointSize: 15
        text: qsTr("Store:")
        anchors.top: title.bottom
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20
    }

    ListModel {
        id: storesModel
        ListElement { text: "Sports" }
        ListElement { text: "Drugstore" }
        ListElement { text: "Cinema" }
        ListElement { text: "Computers" }
    }

    ComboBox {
        id: storesCombobox
        height: 40
        model: storesModel
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.top: storeLabel.bottom
        anchors.topMargin: 20
    }

    Text {
        id: productLabel
        font.pointSize: 15
        text: qsTr("Product:")
        anchors.top: storesCombobox.bottom
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20
    }

    ListModel {
        id: productsModel
        ListElement { text: "Product1" }
        ListElement { text: "Product2" }
        ListElement { text: "Product3" }
        ListElement { text: "Product4" }
    }

    ComboBox {
        id: productsCombobox
        height: 40
        model: productsModel
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 20
        anchors.top: productLabel.bottom
        anchors.topMargin: 20
    }

    Text {
        id: priceLabel
        font.pointSize: 15
        text: qsTr("Price:")
        anchors.top: productsCombobox.bottom
        anchors.topMargin: 20
        anchors.left: parent.left
        anchors.leftMargin: 20
    }

    TextField {
        id: priceTextField
        anchors.top: priceLabel.bottom
        anchors.topMargin: 20
        placeholderText: "$ 0.0"
        anchors.left: parent.left
        anchors.leftMargin: 20
        anchors.right: parent.right
        anchors.rightMargin: 20
    }

    Button {
        id: submitButton
        width: 130
        height: 50
        anchors.right: parent.right
        anchors.rightMargin: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        text: "Submit offer"
        onClicked: specialOffer.clicked(storesCombobox.selectedIndex, productsCombobox.selectedIndex, priceTextField.text)
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
            specialOffer.visible = false
            mainScr.visible = true
        }
    }
}
