import QtQuick 2.5
import QtQuick.Window 2.0

Window {
    id: mainWindow
//    x: Screen.desktopAvailableWidth / 2
    x: (Screen.desktopAvailableWidth - width) / 2
    y: (Screen.desktopAvailableHeight - height) / 2
    width: 1280
    height: 720
    visible: true

    SlideDeck {
        id: presentation
        //scale: 1.0 // TODO: scale to the dedicated resolution
    }
}
