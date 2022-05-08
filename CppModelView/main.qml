import QtQuick 2.15
import QtQuick.Window 2.15
import org.example 1.0

Window {
    width: 640
    height: 480
    visible: true
    title: qsTr("Hello World")

    ListView {
        id: view
        anchors.fill: parent
        model: DataEntryModel {}
        delegate: Text {
            // use the defined model role "display"
            text: model.display
        }
    }
}
