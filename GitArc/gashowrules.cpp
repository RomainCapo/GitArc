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
                          "\t Press the key A, S, D and F to burn the note.\n"
                          "\t Clic on this key when the note is on the the rectangle at the bottom oh the window.\n"
                          "\t You can see your score and another informations on the right panel";

    QLabel *lblDesc = new QLabel(description, this);
    lblDesc->move(QPoint(20,20));
    lblDesc->setFont(QFont(FONT, FONT_SIZE));
}
