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
    GAHorizontalNotesBar(const float _sceneWidth, const float _sceneHeight);
    void isPressed(int);
    void isReleased(int);
    int score();
    QList<QGraphicsRectItem*> noteBurner;

public slots:
    void checkNoteCollision();

private:

    QTimer *timerCollision;
    const float sceneWidth;
    const float sceneHeight;
    float stripWidth;
    QList<int> keyPressed;

    int _score;//temporary
};

#endif // GAHORIZONTALNOTESBAR_H
