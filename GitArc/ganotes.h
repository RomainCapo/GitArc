/**
* This class is a graphic item representing the partition's note
*
* @author	Capocasale Romain, Freiburghaus Jonas, Moulin Vincent
*/

#ifndef GANOTES_H
#define GANOTES_H

#include <QGraphicsEllipseItem>

class GANotes : public QGraphicsEllipseItem
{
public:
    GANotes(QGraphicsEllipseItem *parent = nullptr);
};

#endif // GANOTES_H
