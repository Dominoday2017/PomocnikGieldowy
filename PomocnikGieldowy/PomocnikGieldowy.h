#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PomocnikGieldowy.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <fstream>
#include <vector>
#include <QString.h>
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
#include <stdlib.h> 
#include <time.h>  
#include <QDebug>
#include <QTime>

class PomocnikGieldowy : public QWidget {

    Q_OBJECT

public:

    PomocnikGieldowy(QWidget* parent = nullptr);

private slots:

    float calc_data(float actionValue, QString actionPriceString, float actionPrice);
    bool check_input(float actionValue, float actionPrice);
    void change_result_color(float value, int row);
    void get_data_to_calc(int value);
    std::string generate_new_value(std::string oldValue);
    void change_price_color(std::string newValue, std::string oldValue, int position);
    void save_to_file();
    void read_from_file();
    void set_new_value();
    void calc_all(); 
    void delay();
    void clear();

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
    QPushButton* clearAllBtn;

};
