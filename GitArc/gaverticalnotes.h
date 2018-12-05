/**
* This class is a graphic item composed of n = 5 vertical lines which represents the playable harmonic.
*
* @author	Capocasale Romain, Freiburghaus Jonas, Moulin Vincent
*/

#ifndef GAVERTICALNOTES_H
#define GAVERTICALNOTES_H

#include <QGraphicsWidget>
#include <QPen>

class GAVerticalNotes : public QGraphicsWidget
{
public:
    explicit GAVerticalNotes(const float sceneWidth, const float sceneHeight);
};

#endif // GAVERTICALNOTES_H
