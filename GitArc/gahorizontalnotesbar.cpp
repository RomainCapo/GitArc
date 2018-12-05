#include "gahorizontalnotesbar.h"
#include "constants.h"
#include <QPainter>
#include <QDebug>

/**
* GAHorizontalNotesBar
* GAHorizontalNotesBar's constructor
*
* @param const QRect widgetRect : Should be the graphic view's rect
* @param QGraphicsItem* parent : The QGraphicsItem used as parent
*/
GAHorizontalNotesBar::GAHorizontalNotesBar(int numberOfRectangle, bool isClicked, const QRect widgetRect, QGraphicsItem *parent) : QGraphicsItem(parent), widgetBoundingRect(widgetRect)
{
    //keyPressed = new QList<int>;
    QPen pen(Qt::black, PEN_WIDTH);
    QRectF frame = this->boundingRect();
    float stripWidth = frame.width() / NUM_NOTES;

    QGraphicsRectItem *rect = new QGraphicsRectItem(stripWidth*numberOfRectangle, frame.height() - HEIGHT_NOTES_STRIP, stripWidth, HEIGHT_NOTES_STRIP, this);
    rect->setPen(pen);
    if(isClicked)
    {
        rect->setBrush(Qt::lightGray);
    }
    else
    {
        rect->setBrush(Qt::darkGray);
    }
    rect->setZValue(qreal(0));
    rect->show();
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

}


