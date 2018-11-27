#include "ganotes.h"
#include "constants.h"
#include <QPainter>
#include <QPropertyAnimation>
#include <QDebug>

GANotes::GANotes(const QRect sceneRect, const int idxPosition) : sceneRect(sceneRect)
{
    this->idxPosition = idxPosition;
    // FIXME : Repetition
    QRectF frame = this->boundingRect();
    float stripWidth = frame.width() / NUM_NOTES;
    this->startPosition = QPoint(this->idxPosition * stripWidth, 0);
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
    // FIXME : Pas laisser variable magique et position dynamique.
    painter->drawEllipse(startPosition, 20, 20);
}

void GANotes::animateDropTranslation()
{
    // FIXME : Repetition
    QRectF frame = this->boundingRect();
    float stripWidth = frame.width() / NUM_NOTES;
    // FIXME : Variable magique;
    QPoint endPosition = QPoint(this->idxPosition * stripWidth, frame.height() + 20);

    this->animation = new QPropertyAnimation(this, "pos");
    this->animation->setStartValue(this->startPosition);
    // FIXME : Variable magique;
    this->animation->setDuration(10000);
    this->animation->setEndValue(endPosition);
    this->animation->start(QPropertyAnimation::DeleteWhenStopped);
}
