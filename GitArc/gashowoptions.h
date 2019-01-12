/**
* This class display the options of the game in a modal window
*
* @author	Capocasale Romain, Freiburghaus Jonas, Moulin Vincent
*/

#ifndef GASHOWOPTIONS_H
#define GASHOWOPTIONS_H

#include <QDialog>

class QComboBox;

class GAShowOptions : public QDialog
{
    Q_OBJECT
public:
    GAShowOptions(QWidget *parent = nullptr);

private :
    QComboBox * cbxMusic;
    QComboBox * cbxDifficulty;

public slots:
    void quitOptions();
    void applyMusic();
};

#endif // GASHOWOPTIONS_H
