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
    GAHorizontalNotesBar(const QRectF widgetRect, QGraphicsItem *parent = nullptr);

    // inherited from QGraphicsItem
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;
    void isPressed(int);

private:
    QRectF itemBoundingRect;
    QRectF viewRect;
    QList<int> *keyPressed;
};

#endif // GAHORIZONTALNOTESBAR_H
