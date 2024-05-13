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

    // table for 1 page.
    QTableWidget *table_1 = new QTableWidget(5, 6, tab1);
        
    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 6; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(QString("%1").arg(row * 7 + col + 1));
            table_1->setItem(row, col, item);
        }
    }

    for (int col = 0; col < 6; ++col) {
    QTableWidgetItem *headerItem = new QTableWidgetItem();
    if (col == 0) {
        headerItem->setText("x(i-1)");
    } 
    if (col == 1) {
        headerItem->setText("x(i)");
    } 
    if (col == 2) {
        headerItem->setText("a(i)");
    } 
    if (col == 3) {
        headerItem->setText("b(i)");
    } 
    if (col == 4) {
        headerItem->setText("c(i)");
    } 
    if (col == 5) {
        headerItem->setText("d(i)");
    } 
    table_1->setHorizontalHeaderItem(col, headerItem);
}

    tab1->layout()->addWidget(table_1);
    // table 1 is done.

    // table for 2 page.
    QTableWidget *table_2 = new QTableWidget(5, 7, tab2);
        
    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 7; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(QString("%1").arg(row * 7 + col + 1));
            table_2->setItem(row, col, item);
        }
    }

    for (int col = 0; col < 7; ++col) {
    QTableWidgetItem *headerItem = new QTableWidgetItem();
    if (col == 0) {
        headerItem->setText("x(j)");
    } 
    if (col == 1) {
        headerItem->setText("F(x_j)");
    } 
    if (col == 2) {
        headerItem->setText("S(x_j)");
    } 
    if (col == 3) {
        headerItem->setText("F(x_j) - S(x_j)");
    } 
    if (col == 4) {
        headerItem->setText("F'(x_j)");
    } 
    if (col == 5) {
        headerItem->setText("S'(x_j)");
    } 
    if (col == 6) {
        headerItem->setText("F'(x_j) - S'(x_j)");
    } 
    table_2->setHorizontalHeaderItem(col, headerItem);
}

    tab2->layout()->addWidget(table_2);
    // table 2 is done.

}

Widget::~Widget()
{

}

