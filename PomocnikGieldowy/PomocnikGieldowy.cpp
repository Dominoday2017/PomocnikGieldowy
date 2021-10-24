#include "PomocnikGieldowy.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>

PomocnikGieldowy::PomocnikGieldowy(QWidget* parent)
    : QWidget(parent) {

    auto* calcBtn1 = new QPushButton("Calc", this);
    auto* calcBtn2 = new QPushButton("Calc", this);
    nameLabel1 = new QLabel("KGHM", this);
    valueLabel1 = new QLabel("445zl", this);
    nameLabel2 = new QLabel("ALIOR", this);
    valueLabel2 = new QLabel("4345zl", this);

    auto* gridLayout = new QGridLayout(this);
    gridLayout->addWidget(nameLabel1, 0, 0);
    gridLayout->addWidget(valueLabel1, 0, 1);
    gridLayout->addWidget(calcBtn1, 0, 2);
    gridLayout->addWidget(nameLabel2, 1, 0);
    gridLayout->addWidget(valueLabel2, 1, 1);
    gridLayout->addWidget(calcBtn2, 1, 2);

    setLayout(gridLayout);

    connect(calcBtn1, &QPushButton::clicked, this, &PomocnikGieldowy::calc1);
}

void PomocnikGieldowy::calc1() {
    nameLabel1->setText("Dziala");
}
