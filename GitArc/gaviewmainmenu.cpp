#include "gaviewmainmenu.h"
#include <QtWidgets>

GAViewMainMenu::GAViewMainMenu(QWidget *parent): QWidget(parent)
{
    setWindowTitle("GitArc Menu");

    vboxLayout = new QVBoxLayout(this);

    btnPlay = new QPushButton("Play GitArc", this);
    btnOption = new QPushButton("Option", this);
    btnQuit = new QPushButton("Quit Game", this);

    vboxLayout->addWidget(btnPlay);
    vboxLayout->addWidget(btnOption);
    vboxLayout->addWidget(btnQuit);

    this->setLayout(vboxLayout);

    this->connect(btnPlay, &QPushButton::clicked, this, &GAViewMainMenu::playGame);
    this->connect(btnQuit, &QPushButton::clicked, this, &QApplication::quit);
}

void GAViewMainMenu::playGame()
{
    GAViewGame *game = new GAViewGame();
}

GAViewMainMenu::~GAViewMainMenu()
{

}
