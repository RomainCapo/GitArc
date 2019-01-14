#include "gashowabout.h"
#include "constants.h"
#include <QLabel>
#include <QFile>

/**
* GAShowAbout
* GAShowAbout constructor
*
* @param QGraphicsItem* parent : The QGraphicsItem used as parent
*/
GAShowAbout::GAShowAbout(QWidget *parent) : QDialog(parent)
{
    this->setFixedSize(1000, 625);
    this->setModal(true);
    this->setStyleSheet("QWidget {background-color:#0277BD; color:white;}");

    QString aboutText;
    QString fileName(":/res/text/about.txt");

    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly))
    {
        aboutText = file.readAll();
        file.close();
    }

    QLabel *lblDesc = new QLabel(aboutText, this);
    lblDesc->move(QPoint(20,20));
    lblDesc->setFont(QFont(FONT, FONT_SIZE));
}
