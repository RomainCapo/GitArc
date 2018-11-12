#ifndef GAVIEWMAINMENU_H
#define GAVIEWMAINMENU_H

#include <QGraphicsView>
#include <QStackedLayout>
#include "gaviewgame.h"

class QPushButton;

class GAViewMainMenu : public QGraphicsView
{
    Q_OBJECT

public:
    GAViewMainMenu(QGraphicsView *parent = 0);

    ~GAViewMainMenu();

public slots:
    void action();

private :
    QPushButton * btnPlay;
    QPushButton * btnQuit;
    QPushButton * btnOption;
    QGraphicsScene *scene;
    QStackedLayout *stackView;
};

#endif // GAVIEWMAINMENU_H
