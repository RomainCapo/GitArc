#include "gaviewgame.h"
#include "gaverticalnotes.h"
#include "gahorizontalnotesbar.h"
#include <QGraphicsLinearLayout>
#include <QGraphicsWidget>
#include <QDebug>

GAViewGame::GAViewGame(QSize layoutSize, QGraphicsView *parent) : QGraphicsView(parent)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    this->setScene(scene);
    this->setSceneRect(0, 0, layoutSize.width(), layoutSize.height());

    this->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    this->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );

    QRect mySceneRect(sceneRect().x(), sceneRect().y(), sceneRect().width(), sceneRect().height());

    GAVerticalNotes *verticalNotes = new GAVerticalNotes(mySceneRect);
    scene->addItem(verticalNotes);

    GAHorizontalNotesBar *horizontalNotes = new GAHorizontalNotesBar(mySceneRect);
    scene->addItem(horizontalNotes);

    this->show();
}
