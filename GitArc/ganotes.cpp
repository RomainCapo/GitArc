#include "ganotes.h"
#include "constants.h"
#include <QPainter>

GANotes::GANotes(const QRect widgetRect, QGraphicsEllipseItem *parent) : QGraphicsEllipseItem(parent), widgetBoundingRect(widgetRect)
{
}

QRectF GANotes::boundingRect() const
{
    return this->widgetBoundingRect;
}

void GANotes::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
//    QRectF frame = this->boundingRect();
//    float stripWidth = frame.width() / NUM_NOTES;
    QPen pen(Qt::black, PEN_WIDTH);
    painter->setPen(pen);
    painter->setBrush(Qt::red);
    // FIXME : Pas laisser variable magique et position dynamique.
    painter->drawEllipse(QPoint(0, 0), 20, 20);
}
