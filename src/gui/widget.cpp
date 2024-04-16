#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("LobachevskyLab");

    // Получение размеров экрана
    QScreen *screen = QGuiApplication::primaryScreen();
    QRect screenGeometry = screen->geometry();
    int screenWidth = screenGeometry.width();
    int screenHeight = screenGeometry.height();

    // Установка размера главного окна в 60% от размеров экрана
    int mainWindowWidth = 0.7 * screenWidth;
    int mainWindowHeight = 0.7 * screenHeight;

    resize(mainWindowWidth, mainWindowHeight);

    int x = (screenWidth - this->width()) / 2;
    int y = (screenHeight - this->height()) / 2;
    move(x, y); 

    
}

Widget::~Widget()
{

}

