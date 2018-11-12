#include "gaviewmainmenu.h"
#include <QtWidgets>

GAViewMainMenu::GAViewMainMenu(QGraphicsView *parent)
    : QGraphicsView(parent)
{
    this->stackView = new QStackedLayout();

    btnPlay = new QPushButton("Fes");

    scene = new QGraphicsScene(this);
    scene->addWidget(btnPlay);
    this->setScene(scene);

    //this->stackView->addWidget(this);

    this->connect(btnPlay, &QPushButton::clicked, this, &GAViewMainMenu::action);
}

void GAViewMainMenu::action()
{
    GAViewGame * game = new GAViewGame();
    stackView->addWidget(game);
}

GAViewMainMenu::~GAViewMainMenu()
{

}
