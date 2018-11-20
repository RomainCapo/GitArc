#include "gaviewgame.h"
#include "gaverticalnotes.h"

GAViewGame::GAViewGame(QGraphicsView *parent) : QGraphicsView(parent)
{
    this->showFullScreen();

    QGraphicsScene *scene = new QGraphicsScene(this);
    this->setScene(scene);

    GAVerticalNotes *verticalNotes = new GAVerticalNotes(this->rect());
    scene->addItem(verticalNotes);

    this->show();
}
