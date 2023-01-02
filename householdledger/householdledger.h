#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_householdledger.h"

class householdledger : public QMainWindow
{
    Q_OBJECT

public:
    householdledger(QWidget *parent = nullptr);
    ~householdledger();

private:
    void changeQssFile(const bool& bOn);
    void makeGUI();
    QString getQssFileName(const bool& bOn);
    void makeStatusBar();

    QToolButton* toggleButton;

private:
    Ui::householdledgerClass ui;
};
