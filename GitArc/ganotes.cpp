#include "ganotes.h"
#include "constants.h"
#include <QPainter>
#include <QPropertyAnimation>
#include <QDebug>

GANotes::GANotes(const QRect sceneRect, const int idxPosition) : sceneRect(sceneRect)
{
    this->idxPosition = idxPosition;
    float stripWidth = this->boundingRect().width() / NUM_NOTES;
    float leftStripMargin = 0.25 * stripWidth;
    float xPos = leftStripMargin + this->idxPosition * stripWidth / 2;
    qDebug() << xPos;
    // FIXME : 0 var magique ?
    this->startPosition = QPoint(xPos, 0);
    qDebug() << this->startPosition;
    this->animateDropTranslation();
}

QRectF GANotes::boundingRect() const
{
    return this->sceneRect;
}

void GANotes::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen(Qt::black, PEN_WIDTH);
    painter->setPen(pen);
    painter->setBrush(Qt::red);
    painter->drawEllipse(this->startPosition, NOTE_RADIUS, NOTE_RADIUS);
}

void GANotes::animateDropTranslation()
{
    QPoint endPosition = QPoint(this->startPosition.x(), this->boundingRect().height() + NOTE_RADIUS);
    this->animation = new QPropertyAnimation(this, "pos");
    this->animation->setStartValue(this->startPosition);
    // FIXME : Variable magique;
    this->animation->setDuration(10000);
    this->animation->setEndValue(endPosition);
    this->animation->start(QPropertyAnimation::DeleteWhenStopped);
}
