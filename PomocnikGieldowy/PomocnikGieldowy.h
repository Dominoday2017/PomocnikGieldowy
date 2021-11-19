#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PomocnikGieldowy.h"

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <iostream>
#include <QMessageBox>
#include <ctime>
#include <math.h>
#include <cmath>
#include <thread>
#include <chrono>
#include <QTimer>

class PomocnikGieldowy : public QWidget {

    Q_OBJECT

public:
    PomocnikGieldowy(QWidget* parent = nullptr);
    void runMultiThread();

private slots:

    float calc_data(float actionValue, QString actionPriceString, float actionPrice);
    bool check_input(float actionValue, float actionPrice);
    void change_result_color(float value, int row);
    void get_data1();
    void get_data2();
    void get_data3();
    void get_data4();
    void save_to_file();
    void read_from_file();
    std::string generate_new_value(std::string oldValue);
    void set_new_value();
    void calc_all();
    

private:
    QLabel* nameLabel1;
    QLabel* nameLabel2;
    QLabel* nameLabel3;
    QLabel* nameLabel4;

    QLabel* valueLabel1;
    QLabel* valueLabel2;
    QLabel* valueLabel3;
    QLabel* valueLabel4;

    QLineEdit* actionValue1;
    QLineEdit* actionValue2;
    QLineEdit* actionValue3;
    QLineEdit* actionValue4;

    QLineEdit* actionPrice1;
    QLineEdit* actionPrice2;
    QLineEdit* actionPrice3;
    QLineEdit* actionPrice4;

    QPushButton* calcBtn1;
    QPushButton* calcBtn2;
    QPushButton* calcBtn3;
    QPushButton* calcBtn4;

    QLabel* resultLabel1;
    QLabel* resultLabel2;
    QLabel* resultLabel3;
    QLabel* resultLabel4;

    QPushButton* restoreBtn;
    QPushButton* calcAllBtn;
    QPushButton* saveBtn;

};
