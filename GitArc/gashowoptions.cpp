#include "gashowoptions.h"
#include "constants.h"
#include "gasettings.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

/**
* GAShowOptions
* GAShowOptions constructor
*
* @param QGraphicsItem* parent : The QGraphicsItem used as parent
*/
GAShowOptions::GAShowOptions(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle(tr("Options"));
    this->setModal(true);
    this->setFixedSize(1000, 600);
    this->setStyleSheet("QWidget {background-color:#0277BD; color:white;}"
                        "QPushButton {background-color: transparent; border-radius: 15; border: 4 solid #E1F5FE; color: rgb(250, 250, 250); font-size: 25px; font-weight: bold;}"
                        "QPushButton:hover { background-color: rgb(129, 212, 250);}"
                        "QComboBox {background-color:white; color:black;}");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QLabel *lblMusic = new QLabel(tr("Change game music : "), this);
    lblMusic->setFont(QFont(FONT, FONT_SIZE));

    cbxMusic = new QComboBox(this);
    cbxMusic->insertItem(0,"A$ap Ferg - New Level");
    cbxMusic->insertItem(1,"Desiigner - Panda");
    cbxMusic->insertItem(2,"50 Cent - P.I.M.P");
    cbxMusic->setFont(QFont(FONT, FONT_SIZE));

    QLabel *lblDifficulty = new QLabel(tr("Change difficulty : "), this);
    lblDifficulty->setFont(QFont(FONT, FONT_SIZE));

    cbxDifficulty = new QComboBox(this);
    cbxDifficulty->insertItem(0, tr("Easy"));
    cbxDifficulty->insertItem(1, tr("Medium"));
    cbxDifficulty->insertItem(2, tr("Hard"));
    cbxDifficulty->setFont(QFont(FONT, FONT_SIZE));
    cbxDifficulty->setCurrentIndex(1);// set difficulty to 1

    QPushButton * btnApply = new QPushButton(tr("Apply changes"), this);
    btnApply->setFont(QFont(FONT, FONT_SIZE));
    btnApply->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);

    QPushButton * btnQuit = new QPushButton(tr("Quit Options"), this);
    btnQuit->setFont(QFont(FONT, FONT_SIZE));
    btnQuit->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);

    //add widget to layout
    mainLayout->addWidget(lblMusic);
    mainLayout->addWidget(cbxMusic);
    mainLayout->addWidget(lblDifficulty);
    mainLayout->addWidget(cbxDifficulty);
    mainLayout->addWidget(btnApply);
    mainLayout->addWidget(btnQuit);
    mainLayout->setAlignment(Qt::AlignCenter);
    mainLayout->setSpacing(50);
    this->setLayout(mainLayout);

    this->connect(btnQuit, &QPushButton::clicked, this, &GAShowOptions::quitOptions);
    this->connect(btnApply, &QPushButton::clicked, this, &GAShowOptions::applyMusic);
}

/**
* GAShowOptions
*
* Apply the options to the game and display a message box
*/
void GAShowOptions::applyMusic()
{
    //update GASettings static class with combobox elements
    GASettings::musicId = cbxMusic->currentIndex();
    GASettings::difficulty = cbxDifficulty->currentIndex();

    QMessageBox msgBox;
    msgBox.setText(tr("Options applied"));
    msgBox.setFont(QFont(FONT, FONT_SIZE));
    msgBox.setStyleSheet("QMessageBox {background-color:rgb(79, 195, 247);}"
                         "QPushButton {background-color: transparent; border-radius: 5; border: 2 solid rgb(2, 119, 189); color: rgb(250, 250, 250); font-size: 15px; font-weight: bold; padding: 10px;}"
                     "QPushButton:hover { background-color: rgb(129, 212, 250);}");
    msgBox.exec();

}

/**
* GAShowOptions
*
* quit the options window
*/
void GAShowOptions::quitOptions()
{
    this->close();
}
