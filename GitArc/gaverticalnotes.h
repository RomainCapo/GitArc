/**
* This class is a graphic item composed of n = 5 vertical lines which represents the playable harmonic.
*
* @author	Capocasale Romain, Freiburghaus Jonas, Moulin Vincent
*/

#ifndef GAVERTICALNOTES_H
#define GAVERTICALNOTES_H

#include <QGraphicsItem>
#include <QGraphicsLayoutItem>

class QPainter;

class GAVerticalNotes : public QGraphicsItem
{
public:
    explicit GAVerticalNotes(const QRectF widgetRect, QGraphicsItem *parent = nullptr);

    // inherited from QGraphicsItem
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QRectF itemBoundingRect;
};

#endif // GAVERTICALNOTES_H
