/**
* This class is a graphic item composed of n = 5 vertical lines which represents the playable harmonic.
*
* @author	Capocasale Romain, Freiburghaus Jonas, Moulin Vincent
*/

#ifndef GAVERTICALNOTES_H
#define GAVERTICALNOTES_H

#include <QGraphicsItem>

class QPainter;

class GAVerticalNotes : public QGraphicsItem
{
public:
    explicit GAVerticalNotes(const QRect widgetRect, QGraphicsItem *parent = nullptr);

    QRectF boundingRect() const;

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);

private:
    QRectF widgetBoundingRect;
};

#endif // GAVERTICALNOTES_H
