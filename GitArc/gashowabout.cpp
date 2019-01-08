#include "gashowabout.h"
#include "constants.h"
#include <QLabel>

GAShowAbout::GAShowAbout(QWidget *parent) : QDialog(parent)
{
    this->setFixedSize(1000, 500);
    QString description = "Information : \n"
                          "\t Ecole : He-Arc \n"
                          "\t Cours : Projet P2 \n"
                          "\t Professeur : David Grunenwald, Stephane Beuret \n"
                          "\t Annee scolaire : 2018 - 2019 \n\n\n"
                          "Ressource : \n"
                          "\t A$ap Ferg - New Level : \n"
                          "\t\t License : Music Rights Management, Sony ATV Publishing, UMPG Publishing, EMI \n"
                          "\t\t Lien : https://www.youtube.com/watch?v=Srns7NiO278\n"
                          "\t Snoop Dogg GIF : \n"
                          "\t\t Lien : https://i.giphy.com/media/ZW1efT4aKTKg/giphy.webp \n"
                          "\t ding.wav : \n"
                          "\t\t License : Creative Common \n"
                          "\t\t Lien : https://freesound.org/s/411749/ \n";

    QLabel *lblDesc = new QLabel(description, this);
    lblDesc->setFont(QFont(FONT, FONT_SIZE));

}
