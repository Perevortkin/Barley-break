
import QtQuick 2.0
import com.ics.board 1.0 as Logic

ListModel{
    id: modelData

    function createList(){
        for (var i = 0; i <= 15; i++)
        {
            if(i != 15)
                append({ cubecolor:"lightgreen", name:Logic.board.getName(i), cubeopacity: 1})
            else  append({ cubecolor:"white", name:Logic.board.getName(i), cubeopacity: 0})
        }
    }

    Component.onCompleted: {
        createList();
    }
}
