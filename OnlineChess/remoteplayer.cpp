#include "remoteplayer.h"
#include "mainwindow.h"

RemotePlayer::RemotePlayer(MainWindow *mainWindow, int _color) : Player(mainWindow, _color)
{

}

void RemotePlayer::play()
{
    mainWindow->nowChoose = QPoint(-1,-1) ;
    mainWindow->nowColor = color ;
    mainWindow->setStatus(MainWindow::STATUSOPPTURN) ;
}

void RemotePlayer::gameEnd(int status)
{
    if(status==MainWindow::STATUSTIE){
        mainWindow->sendMessage(mainWindow->MESSAGETIE) ;
    } else if(status==MainWindow::STATUSWHITEWIN){
        mainWindow->sendMessage(mainWindow->MESSAGEWHITEWIN) ;
    } else if(status==MainWindow::STATUSBLACKWIN){
        mainWindow->sendMessage(mainWindow->MESSAGEBLACKWIN) ;
    }
}
