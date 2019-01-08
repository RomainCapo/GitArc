#include "gagamerightpannel.h"

GAGameRightPannel::GAGameRightPannel(QWidget *parent) : QWidget(parent)
{
    this->setStyleSheet("QLabel {font-size: 30px; color:white; font-weight:bold;}");

    this->lbBestScore = new QLabel(this);
    this->setBestScore(GAScore::get()->readBestScore());

    this->lbScore = new QLabel(this);
    this->setScore(0);

    this->lbTotalNote = new QLabel(this);
    this->setTotalNote(0);

    this->lbTotalCorrectNote = new QLabel(this);
    this->setTotalCorrectNote(0);

    QPushButton* btnQuit = new QPushButton("Quit", this);
    btnQuit->setFont(QFont(FONT, FONT_SIZE));
    btnQuit->setStyleSheet("QPushButton { background-color: transparent; border-radius: 15; border: 2 solid rgb(2, 119, 189); color: rgb(250, 250, 250); font-size: 25px; font-weight: bold; padding: 10px 0 10px 0;}"
                           "QPushButton:hover { background-color: rgb(129, 212, 250);}");

    QVBoxLayout *vLayout = new QVBoxLayout(this);
    vLayout->addWidget(lbBestScore);
    vLayout->addWidget(lbScore);
    vLayout->addWidget(lbTotalNote);
    vLayout->addWidget(lbTotalCorrectNote);
    vLayout->addWidget(btnQuit);
    vLayout->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    vLayout->setSpacing(50);
    this->setLayout(vLayout);

    this->connect(btnQuit, &QPushButton::clicked, this, &GAGameRightPannel::quitGame);
}

void GAGameRightPannel::setBestScore(int bestScore)
{
    this->lbBestScore->setText(QString("Best score : %1").arg(bestScore));
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

void GAGameRightPannel::quitGame()
{
    GAMainMenu *gaMainMenu = new GAMainMenu();
    emit quitGameSig();
}
