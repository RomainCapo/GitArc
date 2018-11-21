/**
* Horizontal notes strip this class is a graphic item representing the area where a note should be played.
* The player should play a note when it passes through this strip.
*
* @author	Capocasale Romain, Freiburghaus Jonas, Moulin Vincent
*/

#ifndef GAHORIZONTALNOTESBAR_H
#define GAHORIZONTALNOTESBAR_H

#include <QGraphicsItem>

class QPainter;

class GAHorizontalNotesBar : public QGraphicsItem
{
public:
    GAHorizontalNotesBar(const QRect widgetRect, QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);
private:
    QRectF widgetBoundingRect;
};

#endif // GAHORIZONTALNOTESBAR_H
