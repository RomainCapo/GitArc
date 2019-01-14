#include "gagamerightpannel.h"
#include "gamainmenu.h"
#include <QLabel>
#include <QPushButton>
#include <QVBoxLayout>

GAGameRightPannel::GAGameRightPannel(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("QLabel {font-size: 30px; color:white; font-weight:bold;}");

    this->lbBestScore = new QLabel(this);
    this->setBestScore(GAScore::get()->getBestScore());

    this->lbScore = new QLabel(this);
    this->setScore(0);

    this->lbTotalNote = new QLabel(this);
    this->setTotalNote(0);

    this->lbTotalCorrectNote = new QLabel(this);
    this->setTotalCorrectNote(0);

    QVBoxLayout *vLayout = new QVBoxLayout(this);
    vLayout->addWidget(lbBestScore);
    vLayout->addWidget(lbScore);
    vLayout->addWidget(lbTotalNote);
    vLayout->addWidget(lbTotalCorrectNote);
    vLayout->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    vLayout->setSpacing(50);
    this->setLayout(vLayout);

}

void GAGameRightPannel::setBestScore(int bestScore)
{
    this->lbBestScore->setText(QString(tr("Best score : %1")).arg(bestScore));
}

void GAGameRightPannel::setScore(int score)
{
    this->lbScore->setText(QString(tr("Score : %1")).arg(score));
}

void GAGameRightPannel::setTotalNote(int totalNotes)
{
    this->lbTotalNote->setText(QString(tr("Total notes : %1")).arg(totalNotes));
}

void GAGameRightPannel::setTotalCorrectNote(int totalCorrectNotes)
{
    this->lbTotalCorrectNote->setText(QString(tr("Total correct notes : %1")).arg(totalCorrectNotes));
}
