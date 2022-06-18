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

        model: modelManager.getModel()
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
                        modelManager.remove(index);
                    }
                }


            }

        }
    }

    Row {
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 10
        spacing: 5

        Text {
            height: 40
            text: "type:"
            verticalAlignment: Text.AlignVCenter
        }

        TextField {
            id: typeInput
            width: 60
        }

        Text {
            height: 40
            text: "size:"
            verticalAlignment: Text.AlignVCenter
        }

        TextField {
            id: sizeInput
            width: 60
        }

        Button {
            text: "add"
            onClicked: {
                modelManager.add({"type": typeInput.text, "size": sizeInput.text})
            }
        }

        Button  {
            text: "undo"
            onClicked: {
                modelManager.undo()
            }
        }

        Button  {
            text: "redo"
            onClicked: {
                modelManager.redo()
            }
        }
    }
}
