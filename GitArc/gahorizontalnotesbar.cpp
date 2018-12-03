#include "gahorizontalnotesbar.h"
#include "constants.h"
#include "ganotes.h"
#include <QPainter>
#include <QDebug>

/**
* GAHorizontalNotesBar
* GAHorizontalNotesBar's constructor
*
* @param const QRect widgetRect : Should be the graphic view's rect
* @param QGraphicsItem* parent : The QGraphicsItem used as parent
*/
GAHorizontalNotesBar::GAHorizontalNotesBar(const QRect widgetRect, QGraphicsItem *parent) : QGraphicsItem(parent), widgetBoundingRect(widgetRect)
{
    keyPressed = new QList<int>;
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
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QRectF frame = this->boundingRect();
    float stripWidth = frame.width() / NUM_NOTES;
    QPen pen(Qt::black, PEN_WIDTH);
    painter->setPen(pen);

    for(int i = 0; i < NUM_NOTES; i++)
    {
        painter->setBrush(Qt::darkGray);

        for(int j = 0; j < keyPressed->length(); j++)
        {
            if(i == keyPressed->at(j))
            {
                painter->setBrush(Qt::lightGray);
            }
        }
        //qDebug() << stripWidth*i;
        painter->drawRect(QRectF(stripWidth*i, frame.height() - HEIGHT_NOTES_STRIP, stripWidth, HEIGHT_NOTES_STRIP));
        collision();
    }
}

void GAHorizontalNotesBar::isPressed(int keyPressed)
{
    bool isAlready = false;

    for(int j = 0; j < this->keyPressed->length(); j++)
    {
        if(keyPressed == this->keyPressed->at(j))
        {
            isAlready = true;
            this->keyPressed->removeAt(j);
        }
    }

    if(!isAlready)
    {
        this->keyPressed->append(keyPressed);
        this->update();
    }
}

void GAHorizontalNotesBar::collision()
{
    QList<QGraphicsItem*> listItemsCollision = collidingItems();
    for(int i = 0; i < listItemsCollision.size(); i++)
    {
        if(typeid(*(listItemsCollision[i])) == typeid(GANotes))
        {
            qDebug() << listItemsCollision[i];
        }
    }
}
