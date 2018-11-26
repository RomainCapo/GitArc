#include "gaviewgame.h"
#include "gaverticalnotes.h"
#include "gahorizontalnotesbar.h"
#include <QGraphicsLinearLayout>
#include <QGraphicsWidget>

GAViewGame::GAViewGame(QGraphicsView *parent) : QGraphicsView(parent)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    this->setScene(scene);

    GAVerticalNotes *verticalNotes = new GAVerticalNotes(this->rect());
    scene->addItem(verticalNotes);

    GAHorizontalNotesBar *horizontalNotes = new GAHorizontalNotesBar(this->rect());
    scene->addItem(horizontalNotes);

    this->show();
}
