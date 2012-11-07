// import QtQuick 1.0 // to target S60 5th Edition or Maemo 5
import QtQuick 1.1
import QtDesktop 0.1
import com.indt.components 1.0

Rectangle {
    width: 500
    height: 500

    ShoppingMallSetter {
        id: setter
    }

    Column {
        id: mainScr
        anchors.fill: parent
        anchors.topMargin: 30
        spacing: 30

        Button {
            id: generalInfoButton
            width: 200
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
            text: "General Info"
            onClicked: {
                mainScr.visible = false
                generalInfo.visible = true
            }
        }

        Button {
            id: specialOfferButton
            width: 200
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Special offers"
            onClicked: {
                mainScr.visible = false
                specialOffer.visible = true
            }
        }

        Button {
            id: foodCourtButton
            width: 200
            height: 50
            anchors.horizontalCenter: parent.horizontalCenter
            text: "Food court"
            onClicked: {
                mainScr.visible = false
                foodCourt.visible = true
            }
        }
    }

    GeneralInfo {
        id: generalInfo
        visible: false
        anchors.fill: parent

        onClicked: {
            console.log(index)
            setter.setGeneralInfo(index)
        }
    }

    SpecialOffer {
        id: specialOffer
        visible: false
        anchors.fill: parent
        onClicked: {
            console.log("Store:" + store + ", Product: " +  product + ", Price: " + price)
            setter.setSpecialOffer(store, product, price)
        }
    }

    FoodCourt {
        id: foodCourt
        visible: false
        anchors.fill: parent
        onClicked: {
            console.log("Restaurant:" + restaurant + ", Number: " +  number)
            setter.setFoodCourt(restaurant, number)
        }
    }
}
