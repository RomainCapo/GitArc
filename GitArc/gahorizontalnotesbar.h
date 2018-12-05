/**
* Horizontal notes strip this class is a graphic item representing the area where a note should be played.
* The player should play a note when it passes through this strip.
*
* @author	Capocasale Romain, Freiburghaus Jonas, Moulin Vincent
*/

#ifndef GAHORIZONTALNOTESBAR_H
#define GAHORIZONTALNOTESBAR_H

#include <QGraphicsWidget>
#include <QPen>
#include <QTimer>

class GAHorizontalNotesBar : public QGraphicsWidget
{
public:
    GAHorizontalNotesBar(const float sceneWidth, const float sceneHeight);
    void isPressed(int);
    void isReleased(int);

public slots:
    void checkNoteCollision();

private:
    QList<QGraphicsRectItem*> noteBurner;
    QTimer *timerCollision;
};

#endif // GAHORIZONTALNOTESBAR_H
