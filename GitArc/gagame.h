/**
* This class is a widget item that contain the game and the two informations panels.
*
* @author	Capocasale Romain, Freiburghaus Jonas, Moulin Vincent
*/
#ifndef GAGAME_H
#define GAGAME_H

#include "gaviewgame.h"

#include <QWidget>

class GAGame : public QWidget
{
    Q_OBJECT
public:
    GAGame(QWidget *parent = nullptr);

public slots:
    void quitGame();
    void setMyFocus();

private:
    GAViewGame* gameView;
};

#endif // GAGAME_H
