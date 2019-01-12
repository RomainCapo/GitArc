/**
* This class display the rules of the games in a modal window
*
* @author	Capocasale Romain, Freiburghaus Jonas, Moulin Vincent
*/

#ifndef GASHOWRULES_H
#define GASHOWRULES_H

#include <QDialog>

class GAShowRules : public QDialog
{
    Q_OBJECT
public:
    GAShowRules(QWidget *parent = nullptr);
};

#endif // GASHOWRULES_H
