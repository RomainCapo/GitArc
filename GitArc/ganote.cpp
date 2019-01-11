#include "ganote.h"
#include "constants.h"
#include <QPropertyAnimation>
#include <QDebug>

GANote::GANote(const QPointF startPosition, const float sceneHeight) : startPosition(startPosition), sceneHeight(sceneHeight)
{
    this->prepareGeometryChange();

    QPen pen(Qt::black, PEN_WIDTH);
    this->note = new QGraphicsEllipseItem(this);
    note->setRect(startPosition.x(), startPosition.y(), NOTE_RADIUS, NOTE_RADIUS);
    note->setPen(pen);
    note->setBrush(QColor(3, 169, 244));
    this->animateDropTranslation();
    this->collidingItems();
}

QRectF GANote::boundingRect() const
{
    return this->note->boundingRect();
}

void GANote::setColor(QBrush color)
{
    this->note->setBrush(color);
}

void GANote::pauseAnimation()
{
    if(this->animation->state() == QAbstractAnimation::Running)
        this->animation->pause();
}

void GANote::resumeAnimation()
{
    if(this->animation->state() == QAbstractAnimation::Paused)
        this->animation->resume();

}

void GANote::animateDropTranslation()
{
    QPoint endPosition = QPoint(this->startPosition.x(), this->sceneHeight + NOTE_RADIUS);
    this->animation = new QPropertyAnimation(this, "pos");
    this->animation->setStartValue(this->startPosition);
    this->animation->setDuration(ANIMATION_DURATION);
    this->animation->setEndValue(endPosition);
    this->animation->start(QPropertyAnimation::DeleteWhenStopped);
}
