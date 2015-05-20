import QtQuick 2.4
import QtQuick.Controls 1.3

//import org.qtproject.example 1.0

ApplicationWindow {
    title: qsTr("CPU INFO")
    width: 640
    height: 480
    visible: true
    TableView {
        id: tableView
        width: parent.width
        height: parent.height
         model:myModel;

        TableViewColumn {
            id: titleColumn
            title: "Name"
            role: "name"
            movable: false
            resizable: false
            width: tableView.viewport.width - valueColumn.width
        }

        TableViewColumn {
            id: valueColumn
            title: "Value"
            role: "value"
            movable: false
            resizable: false
            width: tableView.viewport.width / 3
        }
    }
   }
