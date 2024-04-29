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
    int mainWindowWidth = 0.5 * screenWidth;
    int mainWindowHeight = 0.5 * screenHeight;

    resize(mainWindowWidth, mainWindowHeight);

    int x = (screenWidth - this->width()) / 2;
    int y = (screenHeight - this->height()) / 2;
    move(x, y); 

    QVBoxLayout *mainlayout = new QVBoxLayout(this);

    QMenuBar *menuBar = new QMenuBar(this);
    QMenu *fileMenuFile = menuBar->addMenu(tr("&File"));
    mainlayout->setMenuBar(menuBar);

    
    QTabWidget *tabWidget = new QTabWidget(this);
    mainlayout->addWidget(tabWidget);
    tabWidget->resize(mainWindowWidth*0.9, mainWindowHeight*0.9);  // Размер вкладок аналогичен размеру окна


    QWidget *tab1 = new QWidget();
    QWidget *tab2 = new QWidget();
    QWidget *tab3 = new QWidget();

    tabWidget->addTab(tab1, tr("Вкладка 1"));
    tabWidget->addTab(tab2, tr("Вкладка 2"));
    tabWidget->addTab(tab3, tr("Вкладка 3"));


    QLabel *label1 = new QLabel("Контент Вкладки 1", tab1);
    QLabel *label2 = new QLabel("Контент Вкладки 2", tab2);
    QLabel *label3 = new QLabel("Контент Вкладки 3", tab3);


    tab1->setLayout(new QVBoxLayout());
    tab1->layout()->addWidget(label1);

    tab2->setLayout(new QVBoxLayout());
    tab2->layout()->addWidget(label2);

    tab3->setLayout(new QVBoxLayout());
    tab3->layout()->addWidget(label3);
}

Widget::~Widget()
{

}

