#include "gahorizontalnotesbar.h"
#include "constants.h"
#include <QPainter>

/**
* GAHorizontalNotesBar
* GAHorizontalNotesBar's constructor
*
* @param const QRect widgetRect : Should be the graphic view's rect
* @param QGraphicsItem* parent : The QGraphicsItem used as parent
*/
GAHorizontalNotesBar::GAHorizontalNotesBar(const QRect widgetRect, QGraphicsItem *parent) : QGraphicsItem(parent), QGraphicsLayoutItem(), widgetBoundingRect(widgetRect)
{
}

void GAHorizontalNotesBar::setGeometry(const QRectF &geom)
{
    prepareGeometryChange();
    QGraphicsLayoutItem::setGeometry(geom);
    setPos(geom.topLeft());
}

QSizeF GAHorizontalNotesBar::sizeHint(Qt::SizeHint which, const QSizeF &constraint) const
{
    return constraint;
}

/**
* boundingRect
* Function used to get this item's bounding rect
*
* @return QRectF : The item's bounding rectangle
*/
QRectF GAHorizontalNotesBar::boundingRect() const
{
    return this->widgetBoundingRect;
}

/**
* paint
* Overrided function from QGraphicItem, usually called by QGraphicsView.
* This function paints the basic graphic items composing this customized graphic item.
*/
void GAHorizontalNotesBar::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QRectF rect = boundingRect();
    float stripWidth = rect.width() / NUM_NOTES;
    QPen pen(Qt::darkCyan, PEN_WIDTH);
    painter->setPen(pen);
    painter->setBrush(Qt::cyan);

    for(int i = 0; i < NUM_NOTES; i++)
    {
        painter->drawRect(QRectF(stripWidth * i, rect.height() - HEIGHT_NOTES_STRIP, stripWidth, HEIGHT_NOTES_STRIP));
    }
}
