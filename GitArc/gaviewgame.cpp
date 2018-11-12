#include "gaviewgame.h"
#include <QtWidgets>

GAViewGame::GAViewGame(QGraphicsView *parent) : QGraphicsView(parent)
{
    scene = new QGraphicsScene(this);
    this->setScene(scene);
    btnTest = new QPushButton("test");
    scene->addWidget(btnTest);
}
