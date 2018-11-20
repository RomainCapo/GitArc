#ifndef GAVIEWGAME_H
#define GAVIEWGAME_H

#include <QGraphicsView>

class GAVerticalNotes;

class GAViewGame : public QGraphicsView
{
    Q_OBJECT

public:
    GAViewGame(QGraphicsView *parent = nullptr);
};

#endif // GAVIEWGAME_H
