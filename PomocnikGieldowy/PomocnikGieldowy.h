#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PomocnikGieldowy.h"

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>

class PomocnikGieldowy : public QWidget {

    Q_OBJECT

public:
    PomocnikGieldowy(QWidget* parent = nullptr);

private slots:
    void calc1();

private:
    QLabel* nameLabel1;
    QLabel* nameLabel2;

    QLabel* valueLabel1;
    QLabel* valueLabel2;

    QLineEdit* actionValue1;
    QLineEdit* actionValue2;

    QLineEdit* actionPrice1;
    QLineEdit* actionPrice2;

    QPushButton* calcBtn1;
    QPushButton* calcBtn2;

    QPushButton* saveBtn1;
    QPushButton* saveBtn2;

    QLabel* resultLabel1;
    QLabel* resultLabel2;

};
