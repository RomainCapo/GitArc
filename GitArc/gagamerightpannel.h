#ifndef GAGAMERIGHTPANNEL_H
#define GAGAMERIGHTPANNEL_H

#include "gascore.h"

#include <QWidget>
#include <QLabel>
#include <QVBoxLayout>

class GAGameRightPannel : public QWidget
{
    Q_OBJECT

public:
    explicit GAGameRightPannel(QWidget *parent = nullptr);
    void setBestScore(int);
    void setScore(int);
    void setTotalNote(int);
    void setTotalCorrectNote(int);

private:
    QLabel *lbBestScore;
    QLabel *lbScore;
    QLabel *lbTotalNote;
    QLabel *lbTotalCorrectNote;
};

#endif // GAGAMERIGHTPANNEL_H
