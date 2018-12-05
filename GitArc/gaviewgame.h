/**
* This class is a graphic view which contains all the game's grapical item.
*
* @author	Capocasale Romain, Freiburghaus Jonas, Moulin Vincent
*/

#ifndef GAVIEWGAME_H
#define GAVIEWGAME_H

#include <QGraphicsView>

class GAVerticalNotes;
class GAHorizontalNotesBar;
class QGraphicsLinearLayout;
class QGraphicsWidget;
class QByteArray;

class GAViewGame : public QGraphicsView
{
    Q_OBJECT

public:
    GAViewGame(QSize layoutSize, QGraphicsView *parent = nullptr);
    void keyPressEvent(QKeyEvent *event);
    void drawHorizontalRectangle(bool isClicked, int nbClic);

public slots:
    void drawNoteLine(QByteArray notesLine);

private:
    QGraphicsScene *scene;
    QRect mySceneRect;
    GAVerticalNotes *verticalNotes;
    GAHorizontalNotesBar *horizontalNotes;
};

#endif // GAVIEWGAME_H
