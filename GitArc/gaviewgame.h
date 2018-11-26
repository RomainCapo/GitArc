/**
* This class is a graphic view which contains all the game's grapical item.
*
* @author	Capocasale Romain, Freiburghaus Jonas, Moulin Vincent
*/

#ifndef GAVIEWGAME_H
#define GAVIEWGAME_H

#include <QGraphicsView>

class GAVerticalNotes;
class QGraphicsLinearLayout;
class QGraphicsWidget;

class GAViewGame : public QGraphicsView
{
    Q_OBJECT

public:
    GAViewGame(QGraphicsView *parent = nullptr);
};

#endif // GAVIEWGAME_H
