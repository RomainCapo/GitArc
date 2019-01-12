/**
* This class is a widget implemented as the game's menu
*
* @author	Capocasale Romain, Freiburghaus Jonas, Moulin Vincent
*/

#ifndef GAVIEWMAINMENU_H
#define GAVIEWMAINMENU_H

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

public slots:
    void showGame();
    void showAbout();
    void showOptions();
    void showRules();
};

#endif // GAVIEWMAINMENU_H
