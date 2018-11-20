#include "gaverticalnotes.h"
#include "constants.h"
#include <QPainter>

/**
* GAVerticalNotes
* GAVerticalNote's constructor
*
* @param const QRect widgetRect : Should be the graphic view's rect
* @param QGraphicsItem* parent : The QGraphicsItem used as parent
*/
GAVerticalNotes::GAVerticalNotes(const QRect widgetRect, QGraphicsItem *parent) : QGraphicsItem(parent), widgetBoundingRect(widgetRect)
{
}

/**
* boundingRect
* Function used to get this item's bounding rect
*
* @return QRectF : The item's bounding rectangle
*/
QRectF GAVerticalNotes::boundingRect() const
{
    return this->widgetBoundingRect;
}

/**
* paint
* Overrided function from QGraphicItem, usually called by QGraphicsView.
* This function paints the basic graphic items composing this customized graphic item.
*/
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
