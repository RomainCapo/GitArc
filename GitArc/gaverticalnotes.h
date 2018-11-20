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
