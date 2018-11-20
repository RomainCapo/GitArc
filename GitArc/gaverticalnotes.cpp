#include "gaverticalnotes.h"
#include "constants.h"
#include <QPainter>

GAVerticalNotes::GAVerticalNotes(const QRect widgetRect, QGraphicsItem *parent) : QGraphicsItem(parent), widgetBoundingRect(widgetRect)
{
}

QRectF GAVerticalNotes::boundingRect() const
{
    return this->widgetBoundingRect;
}

void GAVerticalNotes::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    float stripWidth = rect.width() / NUM_NOTES;
    QPen pen(Qt::black, PEN_WIDTH);
    painter->setPen(pen);

    for(int i = 0; i < NUM_NOTES; i++){
        painter->drawLine(QPoint(stripWidth * i, 0), QPoint(stripWidth * i, rect.height()));
    }
}
