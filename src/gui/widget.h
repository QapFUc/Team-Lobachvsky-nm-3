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
    ~Widget();

private:
    void CreateTable1();
    void CreateTable2();
    void CreateGraphs();
    QTabWidget *tabWidget;
    QWidget *tab1;
    QWidget *tab2;
    QWidget *tab3;
    QWidget *tab4;
};
#endif // WIDGET_H
