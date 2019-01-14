#include "gashowrules.h"
#include "gaconstants.h"
#include <QLabel>
#include <QFile>

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

    QString rulesText;
    QString fileName(":/res/text/rules.txt");

    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly))
    {
        rulesText = file.readAll();
        file.close();
    }

    QLabel *lblDesc = new QLabel(rulesText, this);
    lblDesc->move(QPoint(20,20));
    lblDesc->setFont(QFont(FONT, FONT_SIZE));
}
