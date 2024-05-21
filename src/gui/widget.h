#pragma once

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
#include <QComboBox>
#include <QPushButton>
#include <QString>
#include <QDebug>
#include <QtCharts>

#include <iostream>
#include <signal.h>
#include <cmath>

#include "core/Eval.hpp"
#include "dataTypes/config.hpp"

class Widget : public QWidget {
    Q_OBJECT

public:
    Widget(QWidget* parent = nullptr);

    void CreateTable1();
    void CreateTable2();
    //void CreateGraphs();
    void InitGraphs();
    void CreateGraphs(const CubicSplineInterpolation& spline,const Config& config);
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
    QComboBox* InputTask;
    QPushButton* SendDatabtn;
    
    QWidget* tab4GraphWidget;
    QChartView* chartView;
    QLineSeries* series;
    QChart* chart;
    QValueAxis* axisX;
    QValueAxis* axisY;

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