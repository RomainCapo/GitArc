#ifndef GAVIEWMAINMENU_H
#define GAVIEWMAINMENU_H

#include <QWidget>
#include <QStackedLayout>
#include "gaviewgame.h"

class QPushButton;
class QLabel;

class GAViewMainMenu : public QWidget
{
    Q_OBJECT

public:
    GAViewMainMenu(QWidget *parent = 0);

    ~GAViewMainMenu();

public slots:
    void playGame();

private :
    QLabel *labImg;
    QPushButton * btnPlay;
    QPushButton * btnOption;
    QPushButton * btnQuit;
    QVBoxLayout * vboxLayout;
    QLabel * labInfo;

};

#endif // GAVIEWMAINMENU_H
