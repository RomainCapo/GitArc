/**
* This class is a graphic item representing the partition's note
*
* @author	Capocasale Romain, Freiburghaus Jonas, Moulin Vincent
*/

#ifndef GANOTES_H
#define GANOTES_H

#include <QGraphicsEllipseItem>
#include <QGraphicsWidget>
#include <QPen>

class QPropertyAnimation;

class GANotes : public QGraphicsWidget
{

public:
    GANotes(const QPointF startPosition, const float sceneHeight);

protected:
    QRectF boundingRect() const;

private:
    QPointF startPosition;
    float sceneHeight;
    QPropertyAnimation *animation;
    QGraphicsEllipseItem *note;

    void animateDropTranslation();
};

#endif // GANOTES_H
