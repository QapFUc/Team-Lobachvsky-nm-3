
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
#include <QLineEdit>
#include <QBoxLayout>
#include <Qt>
#include <QComboBox>
#include <QPushButton>

#include <iostream>
#include <signal.h>

#include "core/Eval.hpp"

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget* parent = nullptr);

    void CreateTable1();
    void CreateTable2();
    //void CreateGraphs();
    void CreateGraphs(CubicSplineInterpolation& spline);
    void CreateInfo();
    void ModInfo(CubicSplineInterpolation& spline);
    void InitTabTask();

    ~Widget();

public slots:
    void StartTest();
    void StartMain();
    void StartOscil();
    void SendDatabtnClick();

private:
    QWidget* tabTask;
    QVBoxLayout* MainHLayout;
    QLineEdit* InputN;
    QLineEdit* InputM;
    QLineEdit* InputEps;
    QLineEdit* InputMaxStep;
    QLineEdit* InputOmega;
    QComboBox* InputTask;
    QPushButton* SendDatabtn;

    double a = 2;
    double b = 10;
    int n = 0;
    double step = 0;
    QTabWidget* tabWidget;
    QWidget* tab1;
    QWidget* tab2;
    QWidget* tab3;
    QWidget* tab4;
    QLineEdit* lineEdit_n;
    QLineEdit* lineEdit_N;
    QLineEdit* lineEdit_max1;
    QLineEdit* lineEdit_max1_x;
    QLineEdit* lineEdit_max2;
    QLineEdit* lineEdit_max2_x;
    QLineEdit* lineEdit_max3;
    QLineEdit* lineEdit_max3_x;
    CubicSplineInterpolation Test;
    CubicSplineInterpolation Main;
    CubicSplineInterpolation Oscil;
};
#endif  // WIDGET_H
