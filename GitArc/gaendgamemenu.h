#ifndef GAENDGAMEMENU_H
#define GAENDGAMEMENU_H

#include <QGraphicsWidget>
#include <QGraphicsTextItem>
#include <QPushButton>

class GAEndGameMenu : public QGraphicsWidget
{
    Q_OBJECT

public:
    GAEndGameMenu(int, int);

public slots:
    void toMenu();
    void closeGame();

signals:
    void quitGameSig();
    void toMenuSig();
};

#endif // GAENDGAMEMENU_H
