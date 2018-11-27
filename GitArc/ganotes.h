/**
* This class is a graphic item representing the partition's note
*
* @author	Capocasale Romain, Freiburghaus Jonas, Moulin Vincent
*/

#ifndef GANOTES_H
#define GANOTES_H

#include <QGraphicsEllipseItem>
#include <QGraphicsObject>
#include <QObject>

class QPainter;
class QPropertyAnimation;

class GANotes : public QGraphicsObject
{

public:
    GANotes(const QRect sceneRect, const int idxPosition);

    // inherited from QGraphicsObject
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                   QWidget *widget);

private:
    QRectF sceneRect;
    int idxPosition;
    QPoint startPosition;
    QPropertyAnimation *animation;

    void animateDropTranslation();

};

#endif // GANOTES_H
