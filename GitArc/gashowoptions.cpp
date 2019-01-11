#include "gashowoptions.h"
#include "constants.h"
#include "gasettings.h"
#include <QLabel>
#include <QVBoxLayout>
#include <QComboBox>
#include <QPushButton>
#include <QMessageBox>
#include <QDebug>

GAShowOptions::GAShowOptions(QWidget *parent) : QDialog(parent)
{
    this->setWindowTitle(tr("Options"));
    this->setFixedSize(1000, 600);
    this->setStyleSheet("QWidget {background-color:#0277BD; color:white;}"
                        "QPushButton {background-color: transparent; border-radius: 15; border: 4 solid #E1F5FE; color: rgb(250, 250, 250); font-size: 25px; font-weight: bold;}"
                        "QPushButton:hover { background-color: rgb(129, 212, 250);}"
                        "QComboBox {background-color:white; color:black;}");

    QVBoxLayout *mainLayout = new QVBoxLayout(this);

    QLabel *lblMusic = new QLabel("Change game music : ", this);
    lblMusic->setFont(QFont(FONT, FONT_SIZE));

    cbxMusic = new QComboBox(this);
    cbxMusic->insertItem(0,"A$ap Ferg - New Level");
    cbxMusic->insertItem(1,"Desiigner - Panda");
    cbxMusic->insertItem(2,"50 Cent - P.I.M.P");
    cbxMusic->setFont(QFont(FONT, FONT_SIZE));

    QLabel *lblDifficulty = new QLabel("Change difficulty : ", this);
    lblDifficulty->setFont(QFont(FONT, FONT_SIZE));

    cbxDifficulty = new QComboBox(this);
    cbxDifficulty->insertItem(0, "Easy");
    cbxDifficulty->insertItem(1, "Medium");
    cbxDifficulty->insertItem(2, "Hard");
    cbxDifficulty->setFont(QFont(FONT, FONT_SIZE));

    QPushButton * btnApply = new QPushButton("Apply changes", this);
    btnApply->setFont(QFont(FONT, FONT_SIZE));
    btnApply->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);

    QPushButton * btnQuit = new QPushButton("Quit Options", this);
    btnQuit->setFont(QFont(FONT, FONT_SIZE));
    btnQuit->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);

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

void GAShowOptions::applyMusic()
{
    GASettings::musicId = cbxMusic->currentIndex();
    GASettings::difficulty = cbxDifficulty->currentIndex();

    QMessageBox msgBox;
    msgBox.setText("Options applied");
    msgBox.setFont(QFont(FONT, FONT_SIZE));
    msgBox.setStyleSheet("QMessageBox {background-color:rgb(79, 195, 247);}"
                         "QPushButton {background-color: transparent; border-radius: 5; border: 2 solid rgb(2, 119, 189); color: rgb(250, 250, 250); font-size: 15px; font-weight: bold; padding: 10px;}"
                     "QPushButton:hover { background-color: rgb(129, 212, 250);}");
    msgBox.exec();

}

void GAShowOptions::quitOptions()
{
    this->close();
}
