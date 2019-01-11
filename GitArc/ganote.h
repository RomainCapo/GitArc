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
#include <QBrush>

class QPropertyAnimation;

class GANote : public QGraphicsWidget
{

public:
    GANote(const QPointF startPosition, const float sceneHeight);
    void setColor(QBrush color);
    void pauseAnimation();
    void resumeAnimation();

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
