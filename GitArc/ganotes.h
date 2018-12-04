/**
* This class is a graphic item representing the partition's note
*
* @author	Capocasale Romain, Freiburghaus Jonas, Moulin Vincent
*/

#ifndef GANOTES_H
#define GANOTES_H

#include <QGraphicsEllipseItem>
#include <QGraphicsWidget>
#include <QObject>

class QPainter;
class QPropertyAnimation;

class GANotes : public QGraphicsWidget
{

public:
    GANotes(const QPointF sceneRect, const float sceneHeight);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget) override;

private:
    QPointF startPosition;
    float sceneHeight;
    QPropertyAnimation *animation;
    QRectF * itemBoundingRect;

    void animateDropTranslation();

public:

};

#endif // GANOTES_H
