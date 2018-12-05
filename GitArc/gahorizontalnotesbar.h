/**
* Horizontal notes strip this class is a graphic item representing the area where a note should be played.
* The player should play a note when it passes through this strip.
*
* @author	Capocasale Romain, Freiburghaus Jonas, Moulin Vincent
*/

#ifndef GAHORIZONTALNOTESBAR_H
#define GAHORIZONTALNOTESBAR_H

#include <QGraphicsItem>
#include <QGraphicsLayoutItem>

class QPainter;

class GAHorizontalNotesBar : public QGraphicsItem
{
public:
    GAHorizontalNotesBar(int numberOfRectangle, bool isClicked, const QRect widgetRect, QGraphicsItem *parent = nullptr);

    // inherited from QGraphicsItem
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QRectF widgetBoundingRect;
};

#endif // GAHORIZONTALNOTESBAR_H
