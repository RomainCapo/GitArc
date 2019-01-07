#include "gaviewmainmenu.h"
#include "gagame.h"
#include "constants.h"
#include <QPushButton>
#include <QLabel>
#include <QVBoxLayout>


GAViewMainMenu::GAViewMainMenu(QWidget *parent): QWidget(parent)
{
    this->setWindowTitle(tr("GitArc Menu"));
    this->showFullScreen();
    this->setStyleSheet("QPushButton {background-color: transparent; border-radius: 25; border: 5 solid black}"
                        "QPushButton:hover { background-color: white;}");

    QLabel *lbImg = new QLabel(this);
    lbImg->setPixmap(QPixmap(":res/img/GitArc.PNG"));
    lbImg->setScaledContents(true);

    QPushButton *btnPlay = new QPushButton(tr("&Play GitArc"), this);
    btnPlay->setFont(QFont(FONT, FONT_SIZE));
    btnPlay->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);

    QPushButton *btnOption = new QPushButton(tr("&Option"), this);
    btnOption->setFont(QFont(FONT, FONT_SIZE));
    btnOption->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);

    QPushButton *btnQuit = new QPushButton(tr("&Quit Game"), this);
    btnQuit->setFont(QFont(FONT, FONT_SIZE));
    btnQuit->setFixedSize(BUTTON_WIDTH, BUTTON_HEIGHT);

    QLabel *lbInfo = new QLabel(tr("Game designed by : Capocasale Romain, Freiburghaus Jonas and Moulin Vincent"), this);
    lbInfo->setFont(QFont(FONT, FONT_SIZE));

    QVBoxLayout *vboxLayout = new QVBoxLayout(this);
    vboxLayout->addWidget(lbImg);
    vboxLayout->addWidget(btnPlay);
    vboxLayout->addWidget(btnOption);
    vboxLayout->addWidget(btnQuit);
    vboxLayout->addWidget(lbInfo);
    vboxLayout->setAlignment(Qt::AlignCenter);
    vboxLayout->setSpacing(50);
    this->setLayout(vboxLayout);

    this->connect(btnPlay, &QPushButton::clicked, this, &GAViewMainMenu::onBtnPlayClicked);
    this->connect(btnQuit, &QPushButton::clicked, this, &QApplication::quit);
}

void GAViewMainMenu::onBtnPlayClicked()
{
    this->close();
    GAGame *game = new GAGame();
}

GAViewMainMenu::~GAViewMainMenu()
{
}
