/**
* This class display about information in a modal window
*
* @author	Capocasale Romain, Freiburghaus Jonas, Moulin Vincent
*/

#ifndef GASHOWABOUT_H
#define GASHOWABOUT_H

#include <QDialog>

class GAShowAbout : public QDialog
{
    Q_OBJECT
public:
    GAShowAbout(QWidget *parent = nullptr);
};

#endif // GASHOWABOUT_H
