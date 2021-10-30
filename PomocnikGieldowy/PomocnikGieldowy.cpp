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
    not text in input
    colors
    picture
*/

PomocnikGieldowy::PomocnikGieldowy(QWidget* parent)
    : QWidget(parent) {

    //---Init all elements---//

    nameLabel1 = new QLabel("KGHM", this);
    nameLabel2 = new QLabel("ALIOR", this);

    valueLabel1 = new QLabel("100zl", this);
    valueLabel2 = new QLabel("4345zl", this);

    actionValue1 = new QLineEdit(this);
    actionValue2 = new QLineEdit(this);
    actionValue1->setPlaceholderText("Ilosc akcji");
    actionValue2->setPlaceholderText("Ilosc akcji");
   
    actionPrice1 = new QLineEdit(this);
    actionPrice2 = new QLineEdit(this);
    actionPrice1->setPlaceholderText("Po cenie..");
    actionPrice2->setPlaceholderText("Po cenie..");

    calcBtn1 = new QPushButton("Policz", this);
    calcBtn2 = new QPushButton("Policz", this);
 
    saveBtn1 = new QPushButton("Zapisz", this);
    saveBtn2 = new QPushButton("Zapisz", this);

    resultLabel1 = new QLabel("0", this);
    resultLabel2 = new QLabel("0", this);
    auto result1 = new QLabel("Zysk/strata: ");
    auto result2 = new QLabel("Zysk/strata: ");

    restoreBtn = new QPushButton("Przywroc z pamieci", this);
    refreshBtn = new QPushButton("Odswiez akcje");

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
    gridLayout->addWidget(saveBtn1, 0, 7);
    
    //Second row

    gridLayout->addWidget(nameLabel2, 1, 0);
    gridLayout->addWidget(valueLabel2, 1, 1);
    gridLayout->addWidget(actionValue2, 1, 2);
    gridLayout->addWidget(actionPrice2, 1, 3);
    gridLayout->addWidget(result2, 1, 4);
    gridLayout->addWidget(resultLabel2, 1, 5);
    gridLayout->addWidget(calcBtn2, 1, 6);
    gridLayout->addWidget(saveBtn2, 1, 7);

    //Last row

    gridLayout->addWidget(restoreBtn, 2, 6);
    gridLayout->addWidget(refreshBtn, 2, 7);

    //---Set Layout---//

    setLayout(gridLayout);

    //---Add button functionality---//

    connect(calcBtn1, &QPushButton::clicked, this, &PomocnikGieldowy::get_data1);
    connect(calcBtn2, &QPushButton::clicked, this, &PomocnikGieldowy::get_data2);
    connect(saveBtn1, &QPushButton::clicked, this, &PomocnikGieldowy::save_to_file1);
}

//---Operations on actions---//

float tax = 0.003;

float PomocnikGieldowy::calc_data(float actionValue, QString actionPriceString, float actionPrice) {

    float actionActualPrice = actionPriceString.toFloat();
    float result = (actionActualPrice * actionValue) - (actionValue * actionPrice) - (actionValue * actionActualPrice * tax) - (actionValue * actionPrice * tax);
    return result;
    
}

void PomocnikGieldowy::get_data1() {
    float actionValue = actionValue1->text().toFloat();
    QString actionPriceString = valueLabel1->text().replace("zl", "");
    float actionPrice = actionPrice1->text().toFloat();

    resultLabel1->setText(QString::number(calc_data(actionValue, actionPriceString, actionPrice)));
}

void PomocnikGieldowy::get_data2() {
    float actionValue = actionValue2->text().toFloat();
    QString actionPriceString = valueLabel2->text().replace("zl", "");
    float actionPrice = actionPrice2->text().toFloat();

    resultLabel2->setText(QString::number(calc_data(actionValue, actionPriceString, actionPrice)));
}

void PomocnikGieldowy::get_data3() {

}

void PomocnikGieldowy::get_data4() {

}

void PomocnikGieldowy::save_to_file1() {
    std::ofstream userData;
    userData.open("data.txt");

    std::string actionPrice = actionPrice1->text().toStdString();
    std::string actionValue = actionValue1->text().toStdString();

    userData << actionValue;
    userData << " ";
    userData << actionPrice;
    userData << "\n";

    userData.close();
    

}

void PomocnikGieldowy::get_actual_data1() {

}