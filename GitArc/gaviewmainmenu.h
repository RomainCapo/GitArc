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

class GAViewMainMenu : public QWidget
{
    Q_OBJECT

public:
    GAViewMainMenu(QWidget *parent = 0);

    ~GAViewMainMenu();

public slots:
    void onBtnPlayClicked();

};

#endif // GAVIEWMAINMENU_H
