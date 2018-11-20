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
    void playGame();

};

#endif // GAVIEWMAINMENU_H
