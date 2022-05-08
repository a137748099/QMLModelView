import QtQuick 2.15
import QtQuick.Window 2.15
import QtQuick.Controls 2.15

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ListView {
        id: listview
        clip: true
        width: parent.width
        height: parent.height

        model: myModel
        delegate: Item {
            id: delegate
            width: listview.width
            height: 30
            Row {
                spacing: 5
                Text {
                    text: type
                }

                Text {
                    text: size
                    color: "red"
                }

                Button  {
                    height: parent.height
                    onClicked: {
                        myModel.remove(index);
                    }
                }


            }

        }
    }

    Button  {
        onClicked: {
            myModel.append({"type": "11","size": "222"});
        }
    }
}
