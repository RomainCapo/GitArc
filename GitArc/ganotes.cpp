#include "ganotes.h"
#include "constants.h"
#include <QPropertyAnimation>
#include <QDebug>

GANotes::GANotes(const QPointF startPosition, const float sceneHeight) : startPosition(startPosition), sceneHeight(sceneHeight)
{
    QPen pen(Qt::black, PEN_WIDTH);
    this->note = new QGraphicsEllipseItem(this);
    note->setRect(startPosition.x(), startPosition.y(), NOTE_RADIUS, NOTE_RADIUS);
    note->setPen(pen);
    note->setBrush(Qt::darkCyan);
    this->animateDropTranslation();
    this->collidingItems();
}

QRectF GANotes::boundingRect() const
{
    return this->note->boundingRect();
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
