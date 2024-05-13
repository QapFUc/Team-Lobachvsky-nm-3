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
};
#endif // WIDGET_H
