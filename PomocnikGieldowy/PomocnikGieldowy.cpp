#include "PomocnikGieldowy.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <fstream>
#include <cpr/cpr.h>
#include "gumbo.h"

/*
TODO:
    background
    fonts
    size
    colors
    picture
    try to broke app
*/

PomocnikGieldowy::PomocnikGieldowy(QWidget* parent)
    : QWidget(parent) {

    //---Init all elements---//

    nameLabel1 = new QLabel("KGHM", this);
    nameLabel2 = new QLabel("ALIOR", this);
    nameLabel3 = new QLabel("JSW", this);
    nameLabel4 = new QLabel("PKO", this);

    valueLabel1 = new QLabel("100zl", this);
    valueLabel2 = new QLabel("4345zl", this);
    valueLabel3 = new QLabel("43zl", this);
    valueLabel4 = new QLabel("11zl", this);

    actionValue1 = new QLineEdit(this);
    actionValue2 = new QLineEdit(this);
    actionValue3 = new QLineEdit(this);
    actionValue4 = new QLineEdit(this);
    actionValue1->setPlaceholderText("Ilosc akcji");
    actionValue2->setPlaceholderText("Ilosc akcji");
    actionValue3->setPlaceholderText("Ilosc akcji");
    actionValue4->setPlaceholderText("Ilosc akcji");
   
    actionPrice1 = new QLineEdit(this);
    actionPrice2 = new QLineEdit(this);
    actionPrice3 = new QLineEdit(this);
    actionPrice4 = new QLineEdit(this);
    actionPrice1->setPlaceholderText("Po cenie..");
    actionPrice2->setPlaceholderText("Po cenie..");
    actionPrice3->setPlaceholderText("Po cenie..");
    actionPrice4->setPlaceholderText("Po cenie..");

    calcBtn1 = new QPushButton("Policz", this);
    calcBtn2 = new QPushButton("Policz", this);
    calcBtn3 = new QPushButton("Policz", this);
    calcBtn4 = new QPushButton("Policz", this);

    resultLabel1 = new QLabel("0", this);
    resultLabel2 = new QLabel("0", this);
    resultLabel3 = new QLabel("0", this);
    resultLabel4 = new QLabel("0", this);
    auto result1 = new QLabel("Zysk/strata: ");
    auto result2 = new QLabel("Zysk/strata: ");
    auto result3 = new QLabel("Zysk/strata: ");
    auto result4 = new QLabel("Zysk/strata: ");

    restoreBtn = new QPushButton("Przywroc z pamieci", this);
    refreshBtn = new QPushButton("Odswiez akcje");
    saveBtn = new QPushButton("Zapisz");

    //---Add elements to layout---//

    auto* gridLayout = new QGridLayout(this);
    
    //First row

    gridLayout->addWidget(nameLabel1, 0, 0);
    gridLayout->addWidget(valueLabel1, 0, 1);
    gridLayout->addWidget(actionValue1, 0, 2);
    gridLayout->addWidget(actionPrice1, 0, 3);
    gridLayout->addWidget(result1, 0, 4);
    gridLayout->addWidget(resultLabel1, 0, 5);
    gridLayout->addWidget(calcBtn1, 0, 6);
    
    //Second row

    gridLayout->addWidget(nameLabel2, 1, 0);
    gridLayout->addWidget(valueLabel2, 1, 1);
    gridLayout->addWidget(actionValue2, 1, 2);
    gridLayout->addWidget(actionPrice2, 1, 3);
    gridLayout->addWidget(result2, 1, 4);
    gridLayout->addWidget(resultLabel2, 1, 5);
    gridLayout->addWidget(calcBtn2, 1, 6);

    //third row

    gridLayout->addWidget(nameLabel3, 2, 0);
    gridLayout->addWidget(valueLabel3, 2, 1);
    gridLayout->addWidget(actionValue3, 2, 2);
    gridLayout->addWidget(actionPrice3, 2, 3);
    gridLayout->addWidget(result3, 2, 4);
    gridLayout->addWidget(resultLabel3, 2, 5);
    gridLayout->addWidget(calcBtn3, 2, 6);

    //fourth

    gridLayout->addWidget(nameLabel4, 3, 0);
    gridLayout->addWidget(valueLabel4, 3, 1);
    gridLayout->addWidget(actionValue4, 3, 2);
    gridLayout->addWidget(actionPrice4, 3, 3);
    gridLayout->addWidget(result4, 3, 4);
    gridLayout->addWidget(resultLabel4, 3, 5);
    gridLayout->addWidget(calcBtn4, 3, 6);

    //Last row

    gridLayout->addWidget(restoreBtn, 4, 5);
    gridLayout->addWidget(refreshBtn, 4, 6);
    gridLayout->addWidget(saveBtn, 4, 7);

    //---Set Layout---//

    setLayout(gridLayout);

    //---Add button functionality---//

    connect(calcBtn1, &QPushButton::clicked, this, &PomocnikGieldowy::get_data1);
    connect(calcBtn2, &QPushButton::clicked, this, &PomocnikGieldowy::get_data2);
    connect(calcBtn3, &QPushButton::clicked, this, &PomocnikGieldowy::get_data3);
    connect(calcBtn4, &QPushButton::clicked, this, &PomocnikGieldowy::get_data4);
    connect(saveBtn, &QPushButton::clicked, this, &PomocnikGieldowy::save_to_file);
}

//---Operations on actions---//

float tax = 0.003;

float PomocnikGieldowy::calc_data(float actionValue, QString actionPriceString, float actionPrice) {
    float actionActualPrice = actionPriceString.toFloat();
    float result = (actionActualPrice * actionValue) - (actionValue * actionPrice) - (actionValue * actionActualPrice * tax) - (actionValue * actionPrice * tax);

    return result;
    
}

//check the input

bool PomocnikGieldowy::check_input(float actionValue, float actionPrice) {
    if (actionValue <= 0 || actionPrice <= 0) {
        QMessageBox msgBox;
        msgBox.setText("Mozna wprowadzac tylko liczby dodatnie");
        msgBox.exec();
        return false;
    }
    return true;
}

//change result color

void PomocnikGieldowy::change_result_color(float value, int row) {
    switch (row) {
        case 1:
            if (value < 0) resultLabel1->setStyleSheet("QLabel {color: red;}");
            else if (value == 0) resultLabel1->setStyleSheet("QLabel {color: black;}");
            else resultLabel1->setStyleSheet("QLabel {color: green;}");
            break;

        case 2:
            if (value < 0) resultLabel2->setStyleSheet("QLabel {color: red;}");
            else if (value == 0) resultLabel2->setStyleSheet("QLabel {color: black;}");
            else resultLabel2->setStyleSheet("QLabel {color: green;}");
            break;

        case 3:
            if (value < 0) resultLabel3->setStyleSheet("QLabel {color: red;}");
            else if (value == 0) resultLabel3->setStyleSheet("QLabel {color: black;}");
            else resultLabel3->setStyleSheet("QLabel {color: green;}");
            break;

        case 4:
            if (value < 0) resultLabel4->setStyleSheet("QLabel {color: red;}");
            else if (value == 0) resultLabel4->setStyleSheet("QLabel {color: black;}");
            else resultLabel4->setStyleSheet("QLabel {color: green;}");
            break;
    }
}

//take data from input and calc

void PomocnikGieldowy::get_data1() {
    float actionValue = actionValue1->text().toFloat();
    QString actionPriceString = valueLabel1->text().replace("zl", "");
    float actionPrice = actionPrice1->text().toFloat();

    bool isTrue = check_input(actionValue, actionPrice);
    
    if (isTrue == true) {
        float resultValue = calc_data(actionValue, actionPriceString, actionPrice);
        change_result_color(resultValue, 1);
        resultLabel1->setText(QString::number(resultValue));
    }
}

void PomocnikGieldowy::get_data2() {
    float actionValue = actionValue2->text().toFloat();
    QString actionPriceString = valueLabel2->text().replace("zl", "");
    float actionPrice = actionPrice2->text().toFloat();

    bool isTrue = check_input(actionValue, actionPrice);

    if (isTrue == true) {
        float resultValue = calc_data(actionValue, actionPriceString, actionPrice);
        change_result_color(resultValue, 2);
        resultLabel2->setText(QString::number(resultValue));
    }
}

void PomocnikGieldowy::get_data3() {
    float actionValue = actionValue3->text().toFloat();
    QString actionPriceString = valueLabel3->text().replace("zl", "");
    float actionPrice = actionPrice3->text().toFloat();

    bool isTrue = check_input(actionValue, actionPrice);

    if (isTrue == true) {
        float resultValue = calc_data(actionValue, actionPriceString, actionPrice);
        change_result_color(resultValue, 3);
        resultLabel3->setText(QString::number(resultValue));
    }
}

void PomocnikGieldowy::get_data4() {
    float actionValue = actionValue4->text().toFloat();
    QString actionPriceString = valueLabel4->text().replace("zl", "");
    float actionPrice = actionPrice4->text().toFloat();

    bool isTrue = check_input(actionValue, actionPrice);

    if (isTrue == true) {
        float resultValue = calc_data(actionValue, actionPriceString, actionPrice);
        change_result_color(resultValue, 4);
        resultLabel4->setText(QString::number(resultValue));
    }
}

//save input data to file

void PomocnikGieldowy::save_to_file() {
    std::string data[4][2] = {
        {actionValue1->text().toStdString(), actionPrice1->text().toStdString()},
        {actionValue2->text().toStdString(), actionPrice2->text().toStdString()},
        {actionValue3->text().toStdString(), actionPrice3->text().toStdString()},
        {actionValue4->text().toStdString(), actionPrice4->text().toStdString()}
    };

    try {
        bool isTrue = false;

        for (int x = 0; x < 4; x++) {
            if (data[x][0] == "" || data[x][1] == "") {
                isTrue = false;
                break;
            }
            float value1 = std::stof(data[x][0]);
            float value2 = std::stof(data[x][1]);
            if (value1 < 0 || value2 < 0) {
                isTrue = false;
            }
            else {
                isTrue = true;
            }
        }

        if (isTrue == true) {
            std::fstream userData;
            userData.open("data.txt");

            for (int x = 0; x < 4; x++) {
                for (int y = 0; y < 2; y++) {
                    userData << data[x][y];
                    userData << " ";
                }
                userData << "\n";
            }
            userData.close();

            QMessageBox msgBox;
            msgBox.setText("Pomysle zapisano do pliku");
            msgBox.exec();
        }
        else {
            QMessageBox msgBox;
            msgBox.setText("Blad zapisu do pliku");
            msgBox.exec();
        }

    }catch (...) {
        QMessageBox msgBox;
        msgBox.setText("Blad zapisu do pliku");
        msgBox.exec();
    }
}

void PomocnikGieldowy::get_actual_data1() {

}