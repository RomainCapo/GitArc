#include "gashowrules.h"
#include "constants.h"
#include <QLabel>

/**
* GAShowRules
* GAShowRules constructor
*
* @param QGraphicsItem* parent : The QGraphicsItem used as parent
*/
GAShowRules::GAShowRules(QWidget *parent) : QDialog(parent)
{
    this->setFixedSize(1000, 600);
    this->setModal(true);
    this->setStyleSheet("QWidget {background-color:#0277BD; color:white;}");
    QString description = "Rules : \n"
                          "\t Press the keys A, S, D and F to burn the note.\n"
                          "\t Multiple keys can be pressed simultaneously. \n"
                          "\t Click on the appopriate key when the note is in the the rectangle at the bottom of the window.\n"
                          "\t You can see your score and some other informations on the right panel";

    QLabel *lblDesc = new QLabel(description, this);
    lblDesc->move(QPoint(20,20));
    lblDesc->setFont(QFont(FONT, FONT_SIZE));
}
