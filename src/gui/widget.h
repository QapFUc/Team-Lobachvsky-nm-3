
#ifndef WIDGET_H
#define WIDGET_H

#include <QGuiApplication>
#include <QLabel>
#include <QLayout>
#include <QMenuBar>
#include <QScreen>
#include <QTabWidget>
#include <QTableWidget>
#include <QWidget>

#include <signal.h>
#include <iostream>

#include "core/Eval.hpp"

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget* parent = nullptr);

    void CreateTable1();
    void CreateTable2();
    //void CreateGraphs();
    void CreateGraphs(CubicSplineInterpolation &spline);
    void CreateInfo();

    ~Widget();

public slots:
    void StartTest();
    void StartMain();

private:
    float a = 2;
    float b = 4;
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
    CubicSplineInterpolation Test;
    CubicSplineInterpolation Main;
};
#endif  // WIDGET_H
