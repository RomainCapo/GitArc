#include "gashowabout.h"
#include "constants.h"
#include <QLabel>

/**
* GAShowAbout
* GAShowAbout constructor
*
* @param QGraphicsItem* parent : The QGraphicsItem used as parent
*/
GAShowAbout::GAShowAbout(QWidget *parent) : QDialog(parent)
{
    this->setFixedSize(1000, 600);
    this->setModal(true);
    this->setStyleSheet("QWidget {background-color:#0277BD; color:white;}");
    QString description = "Informations : \n"
                          "\t École : He-Arc \n"
                          "\t Cours : Projet P2 \n"
                          "\t Professeurs : David Grunenwald, Stéphane Beuret \n"
                          "\t Étudiants : Capocasale Romain, Freiburghaus Jonas and Moulin Vincent\n"
                          "\t Annee scolaire : 2018 - 2019 \n\n\n"
                          "Ressources : \n"
                          "\t A$ap Ferg - New Level : \n"
                          "\t\t License : Music Rights Management, Sony ATV Publishing, UMPG Publishing, EMI \n"
                          "\t\t Lien : https://www.youtube.com/watch?v=Srns7NiO278\n"
                          "\t Desiigner - Panda : \n"
                          "\t\t License : Music Rights Management, CMRRA, Kobalt Music Publishing, AMRA, EMI  \n"
                          "\t\t Lien : https://www.youtube.com/watch?v=4NJlUribp3c \n"
                          "\t 50 Cent - P.I.M.P : \n"
                          "\t\t License : Management, Kobalt Music Publishing, EMI Music Publishing, CMRRA, UBEM,   \n"
                          "\t\t Lien : https://www.youtube.com/watch?v=UDApZhXTpH8 \n"
                          "\t Snoop Dogg GIF : \n"
                          "\t\t Lien : https://i.giphy.com/media/ZW1efT4aKTKg/giphy.webp \n"
                          "\t ding.wav : \n"
                          "\t\t License : Creative Common \n"
                          "\t\t Lien : https://freesound.org/s/411749/ \n";
                          "\t error.wav : \n"
                          "\t\t License : Creative Common \n"
                          "\t\t Lien : https://freesound.org/people/Autistic%20Lucario/sounds/142608/";

    QLabel *lblDesc = new QLabel(description, this);
    lblDesc->move(QPoint(20,20));
    lblDesc->setFont(QFont(FONT, FONT_SIZE));

}
