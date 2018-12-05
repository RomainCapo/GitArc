#include "ganotes.h"
#include "gahorizontalnotesbar.h"
#include "constants.h"
#include <QPainter>
#include <QPropertyAnimation>
#include <QDebug>

GANotes::GANotes(const QPointF startPosition, const float sceneHeight) : startPosition(startPosition), sceneHeight(sceneHeight)
{
    QPen pen(Qt::black, PEN_WIDTH);
    QGraphicsEllipseItem* note = new QGraphicsEllipseItem(this);
    note->setRect(startPosition.x(), startPosition.y(), NOTE_RADIUS, NOTE_RADIUS);
    //note->setPen(pen);
    //note->setBrush(Qt::darkCyan);

    itemBoundingRect = new QRectF();

    this->animateDropTranslation();
}

QRectF GANotes::boundingRect() const
{
    itemBoundingRect->setRect(this->x(), this->y(), NOTE_RADIUS, NOTE_RADIUS);
    return *itemBoundingRect;
}

void GANotes::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::blue);
    painter->drawEllipse(boundingRect());
    QList<QGraphicsItem*> listItemsCollision = collidingItems(Qt::IntersectsItemBoundingRect);
    for(int i = 0; i < listItemsCollision.size(); i++)
    {
        if(typeid(*(listItemsCollision[i])) == typeid(GAHorizontalNotesBar))
        {
            painter->drawEllipse(listItemsCollision[i]->pos(), 7,7);

        }
    }
}

void GANotes::animateDropTranslation()
{
    QPoint endPosition = QPoint(this->startPosition.x(), this->sceneHeight + NOTE_RADIUS);
    this->animation = new QPropertyAnimation(this, "pos");
    this->animation->setStartValue(this->startPosition);
    this->animation->setDuration(ANIMATION_DURATION);
    this->animation->setEndValue(endPosition);
    this->animation->start();
    this->connect(this->animation, SIGNAL(finished()), this, SLOT(deleteLater()));
}

