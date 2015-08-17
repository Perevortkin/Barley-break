import QtQuick 2.4
import QtQuick.Controls 1.3
import QtQuick.Window 2.2
import QtQuick.Dialogs 1.2
import com.ics.board 1.0 as Logic
ApplicationWindow{

    id: root
    title: qsTr("Пятнашки")
    visible: true

    menuBar: MenuBar {

        Menu {
            title: qsTr("&File")
            MenuItem {
                text: qsTr("&New game")
                onTriggered: mixCubes();
            }
            MenuItem {
                text: qsTr("E&xit")
                onTriggered:Qt.quit();
            }
        }
    }

    MessageDialog {
        id: messageDialog

        title: qsTr("Victory!!!")

        function show(caption) {
            messageDialog.text = caption;
            messageDialog.open();
        }
    }

    function mixCubes(){
        Logic.board.mixCubes();
        view.model.clear();
        for (var i = 0; i <= 15; i++)
        {
            if(Logic.board.getName(i))
                view.model.append({ cubecolor:"lightgreen", name:Logic.board.getName(i), cubeopacity: 1})
            else  view.model.append({ cubecolor:"white", name:Logic.board.getName(i), cubeopacity: 0})
        }
    }

    width: 900
    height: 900

    Rectangle{
        id:mainRect

        width: parent.width
        height: parent.height

        border.color: "black"

        GridView{
            id: view

            anchors.fill: mainRect
            focus:true
            cellHeight: mainRect.height / 4
            cellWidth: mainRect.width / 4

            interactive: false
            model: Cubes{}

            move: Transition {
                NumberAnimation { easing.type: Easing.OutQuart; properties: "x,y"; duration: 500 }
            }
            add: Transition {
                NumberAnimation { easing.type: Easing.OutQuart; properties: "x,y"; duration: 1000 }
            }
            remove: Transition {
                NumberAnimation { easing.type: Easing.OutQuart; properties: "x,y"; duration: 400 }
            }

            delegate: Component{

                Rectangle{

                    id: delegateRect

                    border.color: "black"

                    function moves(index){

                        if (view.model.get(index).name != " ")
                            view.currentIndex = index;
                        var ind = Logic.board.move(view.currentIndex);
                        if (ind != view.currentIndex)
                        {
                            view.model.move(view.currentIndex,ind,1)
                            if ((view.currentIndex - ind) == 4)
                                view.model.move(ind + 1,view.currentIndex,1)
                            else  if ((view.currentIndex - ind) == -4)
                                view.model.move(ind - 1,view.currentIndex,1)
                        }
                        if (Logic.board.isVictory())
                            messageDialog.show("You have won");
                    }

                    width: view.cellWidth * 0.95
                    height: view.cellHeight * 0.95
                    radius: (height + width) / 20

                    opacity: cubeopacity
                    color: GridView.isCurrentItem ? "red" : cubecolor

                    transform: Scale {origin.x: 25; origin.y: 25; xScale: 1; yScale: 1;}

                    Text{
                        anchors.centerIn: parent

                        font.pointSize: view.cellHeight / 5
                        text: model.name != 0 ? model.name : ""

                        transform: Scale {origin.x: 25; origin.y: 25; xScale: 1; yScale: 1;}
                    }

                    MouseArea{
                        id:rectMouse

                        anchors.fill: parent
                        hoverEnabled: true

                        onEntered: {
                            view.currentIndex = index;
                        }
                        onClicked: {
                            delegateRect.moves(index);
                        }

                    }

                    Behavior on color{
                        ColorAnimation { duration: 200 }
                    }

                }
            }

        }
    }

    Component.onCompleted: mixCubes();
}
