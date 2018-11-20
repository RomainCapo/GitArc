#ifndef GAVIEWGAME_H
#define GAVIEWGAME_H

#include <QGraphicsView>

class QPushButton;

class GAViewGame : public QGraphicsView
{
    Q_OBJECT
public:
    GAViewGame(QGraphicsView *parent = nullptr);
    QPushButton * btnTest;

    QGraphicsScene *scene;
};

#endif // GAVIEWGAME_H
