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

class GAVerticalNotes : public QGraphicsItem, public QGraphicsLayoutItem
{
public:
    explicit GAVerticalNotes(const QRect widgetRect, QGraphicsItem *parent = nullptr);

    // inherited from QGraphicsLayoutItem
    void setGeometry(const QRectF &geom) override;
    QSizeF sizeHint(Qt::SizeHint which, const QSizeF &constraint = QSizeF()) const override;

    // inherited from QGraphicsItem
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);

private:
    QRectF widgetBoundingRect;
};

#endif // GAVERTICALNOTES_H
