/*
    Created by: Dominik Gawlak
*/

#include "PomocnikGieldowy.h"

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

/* Main function */

PomocnikGieldowy::PomocnikGieldowy(QWidget* parent) :
    QWidget(parent)
{
    /* Init UI elements */

    QFont font("Arial", 11, QFont::Bold);
    QFont fontBtn("Arial", 9, QFont::Bold);

    nameLabel1 = new QLabel("KGHM", this);
    nameLabel2 = new QLabel("ALIOR", this);
    nameLabel3 = new QLabel("JSW", this);
    nameLabel4 = new QLabel("PKO", this);

    srand((unsigned)time(0));

    valueLabel1 = new QLabel( RandomFloat(0.1, 300.0) + "zl", this );
    valueLabel2 = new QLabel( RandomFloat(0.1, 300.0) + "zl", this );
    valueLabel3 = new QLabel( RandomFloat(0.1, 300.0) + "zl", this );
    valueLabel4 = new QLabel( RandomFloat(0.1, 300.0) + "zl", this );

    actionValue1 = new QLineEdit(this);
    actionValue2 = new QLineEdit(this);
    actionValue3 = new QLineEdit(this);
    actionValue4 = new QLineEdit(this);

    actionPrice1 = new QLineEdit(this);
    actionPrice2 = new QLineEdit(this);
    actionPrice3 = new QLineEdit(this);
    actionPrice4 = new QLineEdit(this);

    calcBtn1 = new QPushButton("Policz", this);
    calcBtn2 = new QPushButton("Policz", this);
    calcBtn3 = new QPushButton("Policz", this);
    calcBtn4 = new QPushButton("Policz", this);

    resultLabel1 = new QLabel("0zl", this);
    resultLabel2 = new QLabel("0zl", this);
    resultLabel3 = new QLabel("0zl", this);
    resultLabel4 = new QLabel("0zl", this);
    auto result1 = new QLabel("Zysk/strata: ");
    auto result2 = new QLabel("Zysk/strata: ");
    auto result3 = new QLabel("Zysk/strata: ");
    auto result4 = new QLabel("Zysk/strata: ");

    restoreBtn = new QPushButton("Przywroc z pamieci", this);
    calcAllBtn = new QPushButton("Policz wszystko");
    saveBtn = new QPushButton("Zapisz do pamieci");
    clearAllBtn = new QPushButton("Wyczysc wszystko");

    /* Add icons and style to buttons */

    restoreBtn->setIcon(QIcon("C:/Users/gawla/CLionProjects/pomocnik-gieldowy/restore_btn.png"));
    restoreBtn->setIconSize(QSize(45, 45));
    restoreBtn->setFont(fontBtn);

    calcAllBtn->setIcon(QIcon("C:/Users/gawla/CLionProjects/pomocnik-gieldowy/calc_btn.png"));
    calcAllBtn->setIconSize(QSize(45, 45));
    calcAllBtn->setFont(fontBtn);

    saveBtn->setIcon(QIcon("C:/Users/gawla/CLionProjects/pomocnik-gieldowy/save_btn.png"));
    saveBtn->setIconSize(QSize(45, 45));
    saveBtn->setFont(fontBtn);
   
    clearAllBtn->setIcon(QIcon("C:/Users/gawla/CLionProjects/pomocnik-gieldowy/clear_btn.png"));
    clearAllBtn->setIconSize(QSize(40, 40));
    clearAllBtn->setFont(fontBtn);

    /* Add all elementes to layout */
    /*
        nameLabel | valueLabel | actionValue | actionPrice | result | resultLabel | calcBtn
        nameLabel | valueLabel | actionValue | actionPrice | result | resultLabel | calcBtn
        nameLabel | valueLabel | actionValue | actionPrice | result | resultLabel | calcBtn
        nameLabel | valueLabel | actionValue | actionPrice | result | resultLabel | calcBtn
        restoreBtn       |       calcAllBtn       |       saveBtn       |       clearAllBtn
    */

    auto* verticalLayout = new QVBoxLayout(this);
    auto* gridLayout = new QGridLayout(this);
    auto* horizontalLayout = new QHBoxLayout(this);

    verticalLayout->addLayout(gridLayout);
    verticalLayout->addLayout(horizontalLayout);

    QList<QLabel*> nameLabelList = { nameLabel1, nameLabel2, nameLabel3, nameLabel4 };
    QList<QLabel*> valueLabelList = { valueLabel1, valueLabel2, valueLabel3, valueLabel4 };
    QList<QLineEdit*> actionValueList = { actionValue1, actionValue2, actionValue3, actionValue4 };
    QList<QLineEdit*> actionPriceList = { actionPrice1, actionPrice2, actionPrice3, actionPrice4 };
    QList<QLabel*> resultList = { result1, result2, result3, result4 };
    QList<QLabel*> resultLabelList = { resultLabel1, resultLabel2, resultLabel3, resultLabel4 };
    QList<QPushButton*> resultCalcBtnList = { calcBtn1, calcBtn2, calcBtn3, calcBtn4};

    for (int x = 0; x < 4; x++) {
        actionValueList[x]->setPlaceholderText("Ilosc akcji");
        actionPriceList[x]->setPlaceholderText("Po cenie..");
    }

    for (int x = 0; x < 4; x++) {
        gridLayout->addWidget(nameLabelList[x], x, 0);
        gridLayout->addWidget(valueLabelList[x], x, 1);
        gridLayout->addWidget(actionValueList[x], x, 2);
        gridLayout->addWidget(actionPriceList[x], x, 3);
        gridLayout->addWidget(resultList[x], x, 4);
        gridLayout->addWidget(resultLabelList[x], x, 5);
        gridLayout->addWidget(resultCalcBtnList[x], x, 6);
    }

    /* Stylesheet */

    for (int x = 0; x < 4; x++) {
        nameLabelList[x]->setFont(font);
        valueLabelList[x]->setFont(font);
        actionValueList[x]->setFont(font);
        actionPriceList[x]->setFont(font);
        resultList[x]->setFont(font);
        resultLabelList[x]->setFont(font);
        resultCalcBtnList[x]->setFont(fontBtn);

        resultCalcBtnList[x]->setIcon(QIcon("C:/Users/gawla/CLionProjects/pomocnik-gieldowy/calc_btn.png"));
        resultCalcBtnList[x]->setIconSize(QSize(40, 40));

        resultLabelList[x]->setMinimumWidth(100);
    }

    /* Add down buttons to horizontal layout */

    horizontalLayout->addWidget(saveBtn);
    horizontalLayout->addWidget(restoreBtn);
    horizontalLayout->addWidget(calcAllBtn);
    horizontalLayout->addWidget(clearAllBtn);
    
    /* Set main layout */

    setLayout(verticalLayout);

    /* Button functionality */

    connect(resultCalcBtnList[0], &QPushButton::clicked, this, [this] {get_data_to_calc(0); });
    connect(resultCalcBtnList[1], &QPushButton::clicked, this, [this] {get_data_to_calc(1); });
    connect(resultCalcBtnList[2], &QPushButton::clicked, this, [this] {get_data_to_calc(2); });
    connect(resultCalcBtnList[3], &QPushButton::clicked, this, [this] {get_data_to_calc(3); });
    connect(saveBtn, &QPushButton::clicked, this, &PomocnikGieldowy::save_to_file);
    connect(restoreBtn, &QPushButton::clicked, this, &PomocnikGieldowy::read_from_file);
    connect(calcAllBtn, &QPushButton::clicked, this, &PomocnikGieldowy::calc_all);
    connect(clearAllBtn, &QPushButton::clicked, this, &PomocnikGieldowy::clear);

    /* Create threading to update stock values every 7 seconds */

    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, QOverload<>::of(&PomocnikGieldowy::set_new_value));
    timer->start(7000);
}

/* Calculate result */

float PomocnikGieldowy::calc_data(float actionValue, QString actionPriceString, float actionPrice) {
    float tax = 0.003;
    float actionActualPrice = actionPriceString.toFloat();
    float result = (actionActualPrice * actionValue) - (actionValue * actionPrice) - (actionValue * actionActualPrice * tax) - (actionValue * actionPrice * tax);

    return result;
}

/* Check if all input is correct */

bool PomocnikGieldowy::check_input(float actionValue, float actionPrice) {
    if (actionValue <= 0 || actionPrice <= 0) {
        QMessageBox msgBox;
        msgBox.setText("Pole nie moze byc puste / mozna wprowadzac tylko liczby dodatnie");
        msgBox.exec();
        return false;
    }
    return true;
}

/* Change labels color after calc */

void PomocnikGieldowy::change_result_color(float value, int row) {
    QList<QLabel*> actionResultList = { resultLabel1, resultLabel2, resultLabel3, resultLabel4 };

    if (value < 0) actionResultList[row-1]->setStyleSheet("QLabel {color: red;}");
    else if (value == 0) actionResultList[row-1]->setStyleSheet("QLabel {color: black;}");
    else actionResultList[row-1]->setStyleSheet("QLabel {color: green;}");
}

/* Take data from inputand calc */

void PomocnikGieldowy::get_data_to_calc(int value) {
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
        actionResultList[value]->setText(QString::number(resultValue) + "zl");
    }
}

/* Save input data to file */

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

/* Reading data from file and adding them to inputs */

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
    }catch (...) {
        QMessageBox msgBox;
        msgBox.setText("Blad odczytu z pliku");
        msgBox.exec();
    }
}

/* Generate random numbers */

std::string PomocnikGieldowy::generate_new_value(std::string oldValue) {
    float r;
    int value = 0;
    value = (-1 + rand() % 2);

    if(value < 0)
        r = std::stof(oldValue) - static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    else
        r = std::stof(oldValue) + static_cast <float> (rand()) / static_cast <float> (RAND_MAX);
    
    QString str = QString::number(r, 'f', 2);
    str.remove(QRegExp("0+$"));
    str.remove(QRegExp("\\.$"));

    return str.toStdString();
}

/* Make 1 second delay */

void PomocnikGieldowy::delay(){
    QTime dieTime = QTime::currentTime().addSecs(1);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
}

/* Change price labels color */

void PomocnikGieldowy::change_price_color(std::string newValue, std::string oldValue, int position) {
    QList<QLabel*> labelsValueList = { valueLabel1, valueLabel2, valueLabel3, valueLabel4 };

    float newValueFloat = std::stof(newValue);
    float oldValueFloat = std::stof(oldValue);

    if (newValueFloat > oldValueFloat)
        labelsValueList[position]->setStyleSheet(" QLabel {color: green;} ");
    else
        labelsValueList[position]->setStyleSheet(" QLabel {color: red;} ");
}

/* Put generated numbers to label */

void PomocnikGieldowy::set_new_value() {
    srand((unsigned)time(0));

    QList<QLabel*> labelsValueList = { valueLabel1, valueLabel2, valueLabel3, valueLabel4 };
    std::string actionPrice[4];

    for (int x = 0; x < 4; x++)
        actionPrice[x] = labelsValueList[x]->text().toStdString();
    
    for (int x = 0; x < 4; x++) {
        std::string oldValue = labelsValueList[x]->text().toStdString();
        std::string newValue = generate_new_value(actionPrice[x]);
        labelsValueList[x]->setText(QString::fromStdString(newValue + "zl"));

        change_price_color(newValue, oldValue, x);
    }

    delay();

    for (int x = 0; x < 4; x++) 
        labelsValueList[x]->setStyleSheet(" QLabel {color: black;} ");
}

/* Calc every position */

void PomocnikGieldowy::calc_all() {
    for (int x = 0; x < 4; x++) {
        PomocnikGieldowy::get_data_to_calc(x);
    }
}

/* Clear all */

void PomocnikGieldowy::clear() {
    QList<QLabel*> resultLabelList = { resultLabel1, resultLabel2, resultLabel3, resultLabel4 };
    QList<QLineEdit*> actionValueList = { actionValue1, actionValue2, actionValue3, actionValue4 };
    QList<QLineEdit*> actionPriceList = { actionPrice1, actionPrice2, actionPrice3, actionPrice4 };

    for (int x = 0; x < 4; x++) {
        resultLabelList[x]->setText("0zl");
        resultLabelList[x]->setStyleSheet(" QLabel {color: black}; ");
        actionValueList[x]->clear();
        actionPriceList[x]->clear(); 
    }
}