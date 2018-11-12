#ifndef GAVIEWMAINMENU_H
#define GAVIEWMAINMENU_H

#include <QGraphicsView>

class GAViewMainMenu : public QGraphicsView
{
    Q_OBJECT

public:
    GAViewMainMenu(QGraphicsView *parent = 0);
    ~GAViewMainMenu();
};

#endif // GAVIEWMAINMENU_H
