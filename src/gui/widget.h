#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGuiApplication>
#include <QScreen>
#include <QTabWidget>
#include <QLabel>
#include <QLayout>
#include <QMenuBar>
#include <QTableWidget>


#include <signal.h>


class Widget :  public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);

    void CreateTable1();
    void CreateTable2();
    void CreateGraphs();
    void CreateInfo();

    ~Widget();

private:
    QTabWidget *tabWidget;
    QWidget *tab1;
    QWidget *tab2;
    QWidget *tab3;
    QWidget *tab4;
    QLineEdit *lineEdit_n;
    QLineEdit *lineEdit_N;
    QLineEdit *lineEdit_max1;
    QLineEdit *lineEdit_max1_x;
    QLineEdit *lineEdit_max2;
    QLineEdit *lineEdit_max2_x;
    QLineEdit *lineEdit_max3;
    QLineEdit *lineEdit_max3_x;
};
#endif // WIDGET_H
