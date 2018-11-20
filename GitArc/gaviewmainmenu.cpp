#include "gaviewmainmenu.h"
#include <QtWidgets>

GAViewMainMenu::GAViewMainMenu(QWidget *parent): QWidget(parent)
{
    this->setWindowTitle("GitArc Menu");
    this->showFullScreen();

    vboxLayout = new QVBoxLayout(this);

    labImg = new QLabel(this);
    labImg->setPixmap(QPixmap(":imageMenu/guitare.png"));
    labImg->setScaledContents(true);
    btnPlay = new QPushButton("Play GitArc", this);
    btnPlay->setFixedSize(500,100);
    btnOption = new QPushButton("Option", this);
    btnOption->setFixedSize(500,100);
    btnQuit = new QPushButton("Quit Game", this);
    btnQuit->setFixedSize(500,100);
    labInfo = new QLabel("Game designed by : Capocasale Romain, Freiburghaus Jonas and Moulin Vincent", this);
    labInfo->setFont(QFont("SansSerif", 10));

    vboxLayout->addWidget(labImg);
    vboxLayout->addWidget(btnPlay);
    vboxLayout->addWidget(btnOption);
    vboxLayout->addWidget(btnQuit);
    vboxLayout->addWidget(labInfo);
    vboxLayout->setAlignment(Qt::AlignCenter);
    vboxLayout->setSpacing(50);
    this->setLayout(vboxLayout);

    this->connect(btnPlay, &QPushButton::clicked, this, &GAViewMainMenu::playGame);
    this->connect(btnQuit, &QPushButton::clicked, this, &QApplication::quit);
}

void GAViewMainMenu::playGame()
{
    GAViewGame *game = new GAViewGame();
    this->hide();
}

GAViewMainMenu::~GAViewMainMenu()
{

}
