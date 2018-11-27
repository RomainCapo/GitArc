/**
* This class is a graphic item representing the partition's note
*
* @author	Capocasale Romain, Freiburghaus Jonas, Moulin Vincent
*/

#ifndef GANOTES_H
#define GANOTES_H

#include <QGraphicsEllipseItem>

class QPainter;

class GANotes : public QGraphicsEllipseItem
{
public:
    GANotes(const QRect widgetRect, QGraphicsEllipseItem *parent = nullptr);

    // inherited from QGraphicsItem
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);

private:
    QRectF widgetBoundingRect;

};

#endif // GANOTES_H
