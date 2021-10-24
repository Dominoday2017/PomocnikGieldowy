#include "PomocnikGieldowy.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>

PomocnikGieldowy::PomocnikGieldowy(QWidget* parent)
    : QWidget(parent) {

    nameLabel1 = new QLabel("KGHM", this);
    nameLabel2 = new QLabel("ALIOR", this);

    valueLabel1 = new QLabel("445zl", this);
    valueLabel2 = new QLabel("4345zl", this);

    actionValue1 = new QLineEdit(this);
    actionValue2 = new QLineEdit(this);
    actionValue1->setPlaceholderText("Ilosc akcji");
    actionValue2->setPlaceholderText("Ilosc akcji");
   
    actionPrice1 = new QLineEdit(this);
    actionPrice2 = new QLineEdit(this);
    actionPrice1->setPlaceholderText("Po cenie..");
    actionPrice2->setPlaceholderText("Po cenie..");

    calcBtn1 = new QPushButton("Calc", this);
    calcBtn2 = new QPushButton("Calc", this);
 
    saveBtn1 = new QPushButton("Save", this);
    saveBtn2 = new QPushButton("Save", this);

    resultLabel1 = new QLabel("0", this);
    resultLabel2 = new QLabel("0", this);
    auto result1 = new QLabel("wynik: ");
    auto result2 = new QLabel("wynik: ");

    auto* gridLayout = new QGridLayout(this);
    gridLayout->addWidget(nameLabel1, 0, 0);
    gridLayout->addWidget(valueLabel1, 0, 1);
    gridLayout->addWidget(actionValue1, 0, 2);
    gridLayout->addWidget(actionPrice1, 0, 3);
    gridLayout->addWidget(result1, 0, 4);
    gridLayout->addWidget(resultLabel1, 0, 5);
    gridLayout->addWidget(calcBtn1, 0, 6);
    gridLayout->addWidget(saveBtn1, 0, 7);
    

    gridLayout->addWidget(nameLabel2, 1, 0);
    gridLayout->addWidget(valueLabel2, 1, 1);
    gridLayout->addWidget(actionValue2, 1, 2);
    gridLayout->addWidget(actionPrice2, 1, 3);
    gridLayout->addWidget(result2, 1, 4);
    gridLayout->addWidget(resultLabel2, 1, 5);
    gridLayout->addWidget(calcBtn2, 1, 6);
    gridLayout->addWidget(saveBtn2, 1, 7);
    

    setLayout(gridLayout);

    connect(calcBtn1, &QPushButton::clicked, this, &PomocnikGieldowy::calc1);
}

void PomocnikGieldowy::calc1() {
    nameLabel1->setText("Dziala");
}
