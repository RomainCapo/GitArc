#include "gagamerightpannel.h"

GAGameRightPannel::GAGameRightPannel(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("QLabel {font-size: 40px}");

    this->lbScore = new QLabel(this);
    this->setScore(0);

    this->lbTotalNote = new QLabel(this);
    this->setTotalNote(0);

    this->lbTotalCorrectNote = new QLabel(this);
    this->setTotalCorrectNote(0);

    QVBoxLayout *vLayout = new QVBoxLayout(this);
    vLayout->addWidget(lbScore);
    vLayout->addWidget(lbTotalNote);
    vLayout->addWidget(lbTotalCorrectNote);
    vLayout->setAlignment(Qt::AlignTop | Qt::AlignHCenter);
    this->setLayout(vLayout);
}

void GAGameRightPannel::setScore(int score)
{
    this->lbScore->setText(QString("Score : %1").arg(score));
}

void GAGameRightPannel::setTotalNote(int totalNotes)
{
    this->lbTotalNote->setText(QString("Total notes : %1").arg(totalNotes));
}

void GAGameRightPannel::setTotalCorrectNote(int totalCorrectNotes)
{
    this->lbTotalCorrectNote->setText(QString("Total correct notes : %1").arg(totalCorrectNotes));
}
