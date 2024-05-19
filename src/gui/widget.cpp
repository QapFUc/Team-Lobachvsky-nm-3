#include "widget.h"

#include <QtWidgets>
#include <QtCharts>
#include <qwidget.h>

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


    tab1 = new QWidget();
    tab2 = new QWidget();
    tab3 = new QWidget();
    tab4 = new QWidget();


    tabWidget->addTab(tab1, tr("Таблица 1"));
    tabWidget->addTab(tab2, tr("Таблица 2"));
    tabWidget->addTab(tab3, tr("График"));
    tabWidget->addTab(tab4, tr("Справка"));


    QLabel *label1 = new QLabel("Контент Вкладки 1", tab1);
    QLabel *label2 = new QLabel("Контент Вкладки 2", tab2);
    QLabel *label3 = new QLabel("Контент Вкладки 3", tab3);


    tab1->setLayout(new QVBoxLayout());//WARNING!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    tab1->layout()->addWidget(label1);

    tab2->setLayout(new QVBoxLayout());//WARNING!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    tab2->layout()->addWidget(label2);

    tab3->setLayout(new QVBoxLayout());//WARNING!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    tab3->layout()->addWidget(label3);

    CreateTable1();
    // table 1 is done.

    CreateTable2();
    // table 2 is done.

    CreateGraphs();
    // widget 3

    CreateInfo();
    // widget 4 

    
}

Widget::~Widget()
{

}

void Widget::CreateTable1(){
    QTableWidget *table_1 = new QTableWidget(5, 6);

    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 6; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(QString("%1").arg(row * 7 + col + 1));
            table_1->setItem(row, col, item);
        }
    }

    table_1->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    for (int col = 0; col < 6; ++col) {
        QTableWidgetItem *headerItem = new QTableWidgetItem();
        switch (col) {
            case 0: headerItem->setText("x(i-1)"); break;
            case 1: headerItem->setText("x(i)"); break;
            case 2: headerItem->setText("a(i)"); break;
            case 3: headerItem->setText("b(i)"); break;
            case 4: headerItem->setText("c(i)"); break;
            case 5: headerItem->setText("d(i)"); break;
        }
        table_1->setHorizontalHeaderItem(col, headerItem);
    }
    tab1->layout()->addWidget(table_1);
}

void Widget::CreateTable2() {
    QTableWidget *table_2 = new QTableWidget(5, 7, tab2);
        
    for (int row = 0; row < 5; ++row) {
        for (int col = 0; col < 7; ++col) {
            QTableWidgetItem *item = new QTableWidgetItem(QString("%1").arg(row * 7 + col + 1));
            table_2->setItem(row, col, item);
        }
    }

    table_2->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

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
}

void Widget::CreateGraphs() {
    QWidget *tab4GraphWidget = new QWidget();

    QChartView *chartView = new QChartView(tab4GraphWidget);
    chartView->setRenderHint(QPainter::Antialiasing);

    QChart *chart = new QChart();

    QLineSeries *series = new QLineSeries();
    series->append(0, 6);
    series->append(2, 4);
    series->append(3, 8);
    series->append(7, 4);
    series->append(10, 5);
    chart->addSeries(series);

    chart->setTitle("Пример графика");

    chart->createDefaultAxes();

    chartView->setChart(chart);

    tab4GraphWidget->setLayout(new QVBoxLayout()); //WARNING!!!!!!!!!!!!!!!!!!!!!!!!!!!!
    tab3->layout()->addWidget(chartView);

    // tabWidget->addTab(tab4GraphWidget, tr("График"));
}

void Widget::CreateInfo() {
    QVBoxLayout *layout_Vert = new QVBoxLayout();
    QHBoxLayout *layout_1 = new QHBoxLayout();
    QHBoxLayout *layout_2 = new QHBoxLayout();
    tab4->setLayout(layout_Vert);

    QLabel *label_n = new QLabel("Сетка сплайна n =", tab4);
    QLineEdit *lineEdit_n = new QLineEdit();
    lineEdit_n->setMaximumWidth(200);
    layout_1->addWidget(label_n, 0, Qt::AlignRight);
    layout_1->addWidget(lineEdit_n, 0, Qt::AlignLeft);
    layout_Vert->addLayout(layout_1);

    QLabel *label_N = new QLabel("Контрольная сетка N =", tab4);
    QLineEdit *lineEdit_N = new QLineEdit();
    lineEdit_N->setMaximumWidth(200);
    layout_2->addWidget(label_N, 0, Qt::AlignRight);
    layout_2->addWidget(lineEdit_N, 0, Qt::AlignLeft);
    layout_Vert->addLayout(layout_2);

    QLabel *label_text1 = new QLabel("Погрешность сплайна на контрольной сетке: ", tab4);
    layout_Vert->addWidget(label_text1, 0, Qt::AlignCenter); //!!

    QHBoxLayout *layout_3 = new QHBoxLayout();
    QLabel *label_max1 = new QLabel("max |F(x_j) - S(x_j)| = ", tab4);
    lineEdit_max1 = new QLineEdit();
    lineEdit_max1->setMaximumWidth(200);
    layout_3->addWidget(label_max1, 0, Qt::AlignRight);
    layout_3->addWidget(lineEdit_max1, 0, Qt::AlignLeft);
    QLabel *label_max1_x = new QLabel(" при x = ", tab4);
    lineEdit_max1_x = new QLineEdit();
    lineEdit_max1_x->setMaximumWidth(100);
    layout_3->addWidget(label_max1_x, 0, Qt::AlignRight);
    layout_3->addWidget(lineEdit_max1_x, 0, Qt::AlignLeft);
    layout_Vert->addLayout(layout_3);

    QLabel *label_text2 = new QLabel("Погрешность производной на контрольной сетке: ", tab4);
    layout_Vert->addWidget(label_text2, 0, Qt::AlignCenter);

    QHBoxLayout *layout_4 = new QHBoxLayout();
    QLabel *label_max2 = new QLabel("max |F'(x_j) - S'(x_j)| = ", tab4);
    lineEdit_max2 = new QLineEdit();
    lineEdit_max2->setMaximumWidth(200);
    layout_4->addWidget(label_max2, 0, Qt::AlignRight);
    layout_4->addWidget(lineEdit_max2, 0, Qt::AlignLeft);
    QLabel *label_max2_x = new QLabel(" при x = ", tab4);
    lineEdit_max2_x = new QLineEdit();
    lineEdit_max2_x->setMaximumWidth(100);
    layout_4->addWidget(label_max2_x, 0, Qt::AlignRight);
    layout_4->addWidget(lineEdit_max2_x, 0, Qt::AlignLeft);
    layout_Vert->addLayout(layout_4);

    QLabel *label_text3 = new QLabel("Погрешность второй производной на контрольной сетке: ", tab4);
    layout_Vert->addWidget(label_text3, 0, Qt::AlignCenter);

    QHBoxLayout *layout_5 = new QHBoxLayout();
    QLabel *label_max3 = new QLabel("max |F''(x_j) - S''(x_j)| = ", tab4);
    lineEdit_max3 = new QLineEdit();
    lineEdit_max3->setMaximumWidth(200);
    layout_5->addWidget(label_max3, 0, Qt::AlignRight);
    layout_5->addWidget(lineEdit_max3, 0, Qt::AlignLeft);
    QLabel *label_max3_x = new QLabel(" при x = ", tab4);
    lineEdit_max3_x = new QLineEdit();
    lineEdit_max3_x->setMaximumWidth(100);
    layout_5->addWidget(label_max3_x, 0, Qt::AlignRight);
    layout_5->addWidget(lineEdit_max3_x, 0, Qt::AlignLeft);
    layout_Vert->addLayout(layout_5);


}
