/**
* This class is a widget implemented as the game's menu
*
* @author	Capocasale Romain, Freiburghaus Jonas, Moulin Vincent
*/

#ifndef GAVIEWMAINMENU_H
#define GAVIEWMAINMENU_H

#include "gashowabout.h"
#include "gashowoptions.h"
#include "gashowrules.h"

#include <QApplication>
#include <QWidget>

class QPushButton;
class QLabel;
class QStackedLayout;

class GAMainMenu : public QWidget
{
    Q_OBJECT

public:
    GAMainMenu(QWidget *parent = 0);
    ~GAMainMenu();

public slots:
    void showGame();
    void showAbout();
    void showOptions();
    void showRules();

private:
    GAShowAbout* aboutDialog;
    GAShowOptions* optionsDialog;
    GAShowRules* rulesDialog;

};

#endif // GAVIEWMAINMENU_H
