/**
* This class is a widget item that contain the game and the two informations panels.
*
* @author	Capocasale Romain, Freiburghaus Jonas, Moulin Vincent
*/
#ifndef GAGAME_H
#define GAGAME_H
#include "gamainmenu.h"
#include <QWidget>

class QHBoxLayout;
class QLabel;

class GAGame : public QWidget
{
    Q_OBJECT
public:
    GAGame(QWidget *parent = nullptr);

public slots:
    void quitGame();
};

#endif // GAGAME_H
