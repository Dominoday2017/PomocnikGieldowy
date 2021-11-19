#include "PomocnikGieldowy.h"
#include <QGridLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <fstream>
#include <vector>
#include <QString.h>

/*
TODO:
    background
    fonts
    size
    colors
    picture
    try to broke app
    change comment style
*/


PomocnikGieldowy::PomocnikGieldowy(QWidget* parent)
    : QWidget(parent) {
    srand((unsigned)time(0));
    //---Init all elements---//
    QFont f("Arial", 10, QFont::Bold);

    nameLabel1 = new QLabel("KGHM", this);
    nameLabel2 = new QLabel("ALIOR", this);
    nameLabel3 = new QLabel("JSW", this);
    nameLabel4 = new QLabel("PKO", this);

    valueLabel1 = new QLabel( RandomFloat(0.1, 300.0) + "zl", this );
    valueLabel2 = new QLabel( RandomFloat(0.1, 300.0) + "zl", this );
    valueLabel3 = new QLabel( RandomFloat(0.1, 300.0) + "zl", this );
    valueLabel4 = new QLabel( RandomFloat(0.1, 300.0) + "zl", this );

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

    resultLabel1 = new QLabel("", this);
    resultLabel2 = new QLabel("", this);
    resultLabel3 = new QLabel("", this);
    resultLabel4 = new QLabel("", this);
    auto result1 = new QLabel("Zysk/strata: ");
    auto result2 = new QLabel("Zysk/strata: ");
    auto result3 = new QLabel("Zysk/strata: ");
    auto result4 = new QLabel("Zysk/strata: ");

    restoreBtn = new QPushButton("Przywroc z pamieci", this);
    calcAllBtn = new QPushButton("Policz wszystko");
    saveBtn = new QPushButton("Zapisz do pamieci");

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

    gridLayout->addWidget(saveBtn, 4, 5);
    gridLayout->addWidget(restoreBtn, 4, 6);
    gridLayout->addWidget(calcAllBtn, 4, 7);
    
    //---Set Layout---//

    setLayout(gridLayout);

    //---Add button functionality---//

    connect(calcBtn1, &QPushButton::clicked, this, [this] {get_data(0); });
    connect(calcBtn2, &QPushButton::clicked, this, [this] {get_data(1); });
    connect(calcBtn3, &QPushButton::clicked, this, [this] {get_data(2); });
    connect(calcBtn4, &QPushButton::clicked, this, [this] {get_data(3); });
    connect(saveBtn, &QPushButton::clicked, this, &PomocnikGieldowy::save_to_file);
    connect(restoreBtn, &QPushButton::clicked, this, &PomocnikGieldowy::read_from_file);
    connect(calcAllBtn, &QPushButton::clicked, this, &PomocnikGieldowy::calc_all);

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&PomocnikGieldowy::set_new_value));
    timer->start(5000);
}

/* Generate random values after program start */

QString RandomFloat(float a, float b) {
    float random = ((float)rand()) / (float)RAND_MAX;
    float diff = b - a;
    float r = random * diff;

    float result = a + r;

    QString str = QString::number(result, 'f', 2);
    str.remove(QRegExp("0+$"));
    str.remove(QRegExp("\\.$"));

    return str;
}

//---Operations on actions---//

float PomocnikGieldowy::calc_data(float actionValue, QString actionPriceString, float actionPrice) {
    float tax = 0.003;
    float actionActualPrice = actionPriceString.toFloat();
    float result = (actionActualPrice * actionValue) - (actionValue * actionPrice) - (actionValue * actionActualPrice * tax) - (actionValue * actionPrice * tax);

    return result;
}

//check the input

bool PomocnikGieldowy::check_input(float actionValue, float actionPrice) {
    if (actionValue <= 0 || actionPrice <= 0) {
        QMessageBox msgBox;
        msgBox.setText("Pole nie moze byc puste / mozna wprowadzac tylko liczby dodatnie");
        msgBox.exec();
        return false;
    }
    return true;
}

//change result color

void PomocnikGieldowy::change_result_color(float value, int row) {
    QList<QLabel*> actionResultList = { resultLabel1, resultLabel2, resultLabel3, resultLabel4 };

    if (value < 0) actionResultList[row-1]->setStyleSheet("QLabel {color: red;}");
    else if (value == 0) actionResultList[row-1]->setStyleSheet("QLabel {color: black;}");
    else actionResultList[row-1]->setStyleSheet("QLabel {color: green;}");
}

//take data from input and calc

void PomocnikGieldowy::get_data(int value) {
    QList<QLineEdit*> actionValueList = { actionValue1, actionValue2, actionValue3, actionValue4 };
    QList<QLabel*> actionLabelList = { valueLabel1, valueLabel2, valueLabel3, valueLabel4 };
    QList<QLineEdit*> actionPriceList = { actionPrice1, actionPrice2, actionPrice3, actionPrice4 };
    QList<QLabel*> actionResultList = { resultLabel1, resultLabel2, resultLabel3, resultLabel4 };

    float actionValue = actionValueList[value]->text().toFloat();
    QString actionPriceString = actionLabelList[value]->text().replace("zl", "");
    float actionPrice = actionPriceList[value]->text().toFloat();

    bool isTrue = check_input(actionValue, actionPrice);
    if (isTrue == true) {
        float resultValue = calc_data(actionValue, actionPriceString, actionPrice);
        change_result_color(resultValue, value + 1);
        actionResultList[value]->setText(QString::number(resultValue));
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
                    userData << "\n";
                }
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

//reading data from file and adding them to inputs

void PomocnikGieldowy::read_from_file() {
    try {
        std::ifstream userData;
        userData.open("data.txt");

        std::string data[4][2];
        int counter = 0;

        for (int x = 0; x < 4; x++) {
            for (int y = 0; y < 2; y++) {
                std::getline(userData, data[x][y], '\n');
            }   
        }

        userData.close();

        QList<QLineEdit*> actionValueList = { actionValue1, actionValue2, actionValue3, actionValue4 };
        QList<QLineEdit*> actionPriceList = { actionPrice1, actionPrice2, actionPrice3, actionPrice4 };

        for (int x = 0; x < 4; x++) {
            actionValueList[x]->setText(QString::fromStdString(data[x][0]));
            actionPriceList[x]->setText(QString::fromStdString(data[x][1]));
        }

        //actionValue1->setText(QString::fromStdString(data[0][0]));
        //actionValue2->setText(QString::fromStdString(data[1][0]));
        //actionValue3->setText(QString::fromStdString(data[2][0]));
        //actionValue4->setText(QString::fromStdString(data[3][0]));

        //actionPrice1->setText(QString::fromStdString(data[0][1]));
        //actionPrice2->setText(QString::fromStdString(data[1][1]));
        //actionPrice3->setText(QString::fromStdString(data[2][1]));
        //actionPrice4->setText(QString::fromStdString(data[3][1]));

    }catch (...) {
        QMessageBox msgBox;
        msgBox.setText("Blad odczytu z pliku");
        msgBox.exec();
    }
}

std::string PomocnikGieldowy::generate_new_value(std::string oldValue) {
    srand((unsigned)time(0));

    float r;

    if ((-1 + rand() % 2) < 0)
        r = std::stof(oldValue) - static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    else
        r = std::stof(oldValue) + static_cast <float> (rand()) / static_cast <float> (RAND_MAX);

    QString str = QString::number(r, 'f', 2);
    str.remove(QRegExp("0+$"));
    str.remove(QRegExp("\\.$"));

    return str.toStdString();
}

void PomocnikGieldowy::set_new_value() {
    QList<QLabel*> labelsValueList = { valueLabel1, valueLabel2, valueLabel3, valueLabel4 };

    std::string actionPrice[4];
    for (int x = 0; x < 4; x++) {
        actionPrice[x] = labelsValueList[x]->text().toStdString();
    }

    for (int x = 0; x < 4; x++) {
        labelsValueList[x]->setText(QString::fromStdString(generate_new_value(actionPrice[x]) + "zl"));
    }

    //std::string actionPrice1Value = valueLabel1->text().toStdString();
    //std::string actionPrice2Value = valueLabel2->text().toStdString();
    //std::string actionPrice3Value = valueLabel3->text().toStdString();
    //std::string actionPrice4Value = valueLabel4->text().toStdString();


    //valueLabel1->setText(QString::fromStdString(generate_new_value(actionPrice1Value) + "zl"));
    //valueLabel2->setText(QString::fromStdString(generate_new_value(actionPrice2Value) + "zl"));
    //valueLabel3->setText(QString::fromStdString(generate_new_value(actionPrice3Value) + "zl"));
    //valueLabel4->setText(QString::fromStdString(generate_new_value(actionPrice4Value) + "zl"));
}

void PomocnikGieldowy::calc_all() {
    
}