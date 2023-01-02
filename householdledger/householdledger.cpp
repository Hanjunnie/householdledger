#include "householdledger.h"
#include <QFileDialog>
#include <QRadioButton>
#include <QTextStream>
#include <QToolButton>

householdledger::householdledger(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    makeGUI();
    makeStatusBar();
}

householdledger::~householdledger()
{
    if (toggleButton != nullptr)
    {
        delete toggleButton;
        toggleButton = nullptr;
    }
}

void householdledger::changeQssFile(const bool& bOn)
{
    QFile file(getQssFileName(bOn));
    if (file.exists())
    {
        file.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&file);
        QString strContents = ts.readAll();
        qApp->setStyleSheet(strContents);
    }

}

void householdledger::makeGUI()
{
}

QString householdledger::getQssFileName(const bool& bOn)
{
    if (bOn)
        return QString(":/qss/light.qss");

    return QString(":/qss/dark.qss");
}

void householdledger::makeStatusBar()
{
    toggleButton = new QToolButton();
    toggleButton->setCheckable(true);
    toggleButton->setIcon(QIcon(":/svg/toggle-off.svg"));
    connect(toggleButton, &QToolButton::toggled, [&](const bool& bOn)
        {
            changeQssFile(bOn);

			if (bOn)
				toggleButton->setIcon(QIcon(":/svg/toggle-off.svg"));
			else
                toggleButton->setIcon(QIcon(":/svg/toggle-on.svg"));
        });

    ui.statusBar->addWidget(toggleButton);
}
