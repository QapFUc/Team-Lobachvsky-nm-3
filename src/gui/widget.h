#pragma once

#include <functional>
#include <qlineedit.h>
#include <qlineseries.h>
#include <qwidget.h>
#ifndef WIDGET_H
#    define WIDGET_H

#    include <QComboBox>
#    include <QDebug>
#    include <QGuiApplication>
#    include <QLabel>
#    include <QLayout>
#    include <QMenuBar>
#    include <QPushButton>
#    include <QScreen>
#    include <QString>
#    include <QTabWidget>
#    include <QTableWidget>
#    include <QWidget>
#    include <QtCharts>

#    include <cmath>
#    include <iostream>
#    include <signal.h>

#    include "core/Eval.hpp"
#    include "dataTypes/config.hpp"

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget* parent = nullptr);

    void CreateTable1();
    void CreateTable2();
    void CreateTable3();

    void InitGraphs();
    void CreateGraphs(const CubicSplineInterpolation& spline, const Config& config);
    void InitInfo();
    void CreateInfo();
    void ModInfo(CubicSplineInterpolation& spline);
    void InitTabTask();

    void StartTest(const Config& config);
    void StartMain(const Config& config);
    void StartOscil(const Config& config);

    ~Widget();

public slots:
    void SaveAs();
    void SendDatabtnClick();

private:
    Config config;

    QWidget* tabTask;
    QVBoxLayout* MainHLayout;
    QLineEdit* InputXStart;
    QLineEdit* InputXEnd;
    QLineEdit* InputN;
    QLineEdit* InputNC;
    QComboBox* InputTask;
    QPushButton* SendDatabtn;

    QWidget* tab4GraphWidget;
    QChartView* chartView;
    QLineSeries* series_spline;
    QLineSeries* series_func;
    QChart* chart;
    QValueAxis* axisX;
    QValueAxis* axisY;

    QTabWidget* tabWidget;
    QWidget* tab1;
    QWidget* tab2;
    QWidget* tab3;
    QWidget* tab4;
    QWidget* tab5;
    QLineEdit* lineEdit_n;
    QLineEdit* lineEdit_N;
    QLineEdit* lineEdit_max1;
    QLineEdit* lineEdit_max1_x;
    QLineEdit* lineEdit_max2;
    QLineEdit* lineEdit_max2_x;
    QLineEdit* lineEdit_max3;
    QLineEdit* lineEdit_max3_x;
    CubicSplineInterpolation Spline;
    std::function<double(double)> Func;
    std::function<double(double)> dFunc;
    std::function<double(double)> ddFunc;

    double max1;
    double max1_x;
    double max2;
    double max2_x;
    double max3;
    double max3_x;
};
#endif  // WIDGET_H