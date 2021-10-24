#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_PomocnikGieldowy.h"

#include <QWidget>
#include <QApplication>
#include <QPushButton>
#include <QLabel>

class PomocnikGieldowy : public QWidget {

    Q_OBJECT

public:
    PomocnikGieldowy(QWidget* parent = nullptr);

private slots:
    void calc1();

private:
    QLabel* nameLabel1;
    QLabel* valueLabel1;
    QLabel* nameLabel2;
    QLabel* valueLabel2;

};
