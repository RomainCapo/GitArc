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
                          "\t Clic on this key when the note are on the the rectangle at the bottom oh the window.\n"
                          "\t You can see your score and another informations on the right panel. \n"
                          "\t When you burn a note, if it become green, the note is burn and you win 100 points. \n"
                          "\t if it become orange, the note is partially burn and you win a few points. \n"
                          "\t if the horizontal note bar become red, you don't have burn the note and you lose 50 points. \n"
                          "\t if the note go out of the screen without being burned, you lose 20 points.";

    QLabel *lblDesc = new QLabel(description, this);
    lblDesc->move(QPoint(20,20));
    lblDesc->setFont(QFont(FONT, FONT_SIZE));
}
