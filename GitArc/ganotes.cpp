#include "ganotes.h"
#include "constants.h"
#include <QPainter>
#include <QPropertyAnimation>
#include <QDebug>

GANotes::GANotes(const QPointF startPosition, const float sceneHeight) : startPosition(startPosition), sceneHeight(sceneHeight)
{
    QPen pen(Qt::black, PEN_WIDTH);
    QGraphicsEllipseItem* note = new QGraphicsEllipseItem(this);
    note->setRect(startPosition.x(), startPosition.y(), NOTE_RADIUS, NOTE_RADIUS);
    note->setPen(pen);
    note->setBrush(Qt::darkCyan);
    this->animateDropTranslation();
}

void GANotes::animateDropTranslation()
{
    QPoint endPosition = QPoint(this->startPosition.x(), this->sceneHeight + NOTE_RADIUS);
    this->animation = new QPropertyAnimation(this, "pos");
    this->animation->setStartValue(this->startPosition);
    this->animation->setDuration(ANIMATION_DURATION);
    this->animation->setEndValue(endPosition);
    this->animation->start();
}
