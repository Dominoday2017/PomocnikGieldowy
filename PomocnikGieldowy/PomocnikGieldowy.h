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

class PomocnikGieldowy : public QWidget {

    Q_OBJECT

public:
    PomocnikGieldowy(QWidget* parent = nullptr);

private slots:

    float calc_data(float actionValue, QString actionPriceString, float actionPrice);
    bool check_input(float actionValue, float actionPrice);
    void change_result_color(float value, int row);
    void get_data1();
    void get_data2();
    void get_data3();
    void get_data4();
    void save_to_file1();
    void save_to_file2();
    void save_to_file3();
    void save_to_file4();
    void write_to_file(std::string actionValue, std::string actionPrice, int row);
    void get_actual_data1();
    

private:
    QLabel* nameLabel1; //delete
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

    QPushButton* saveBtn1;
    QPushButton* saveBtn2;
    QPushButton* saveBtn3;
    QPushButton* saveBtn4;

    QLabel* resultLabel1;
    QLabel* resultLabel2;
    QLabel* resultLabel3;
    QLabel* resultLabel4;

    QPushButton* restoreBtn;
    QPushButton* refreshBtn;

};
