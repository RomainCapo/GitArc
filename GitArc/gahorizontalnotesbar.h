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
#include <QSound>

class GAHorizontalNotesBar : public QGraphicsWidget
{
public:
    GAHorizontalNotesBar(const float _sceneWidth, const float _sceneHeight);
    void highlightFret(int);
    void toBasicFret(int);
    QList<QGraphicsRectItem*> noteBurner;

public slots:
    void wrongNotePlayed(int);

private:

    const float sceneWidth;
    const float sceneHeight;
    float stripWidth;
    QSound *bellSound;
};

#endif // GAHORIZONTALNOTESBAR_H
