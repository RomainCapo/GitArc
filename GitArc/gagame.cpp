#include "gagame.h"
#include "gaviewgame.h"
#include <QHBoxLayout>
#include <QLabel>

GAGame::GAGame(QWidget *parent) : QWidget(parent)
{
    this->showFullScreen();

    GAViewGame *gameView = new GAViewGame();

    QLabel *lbScore = new QLabel(this);
    lbScore->setText("Score : 0");

    QLabel *lbTemp = new QLabel(this);
    lbTemp->setText("Temporary");

    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(lbTemp);
    hLayout->setStretch(0, 1);
    hLayout->addWidget(gameView);
    hLayout->setStretch(1, 3);
    hLayout->addWidget(lbScore);
    hLayout->setStretch(2, 1);
    this->setLayout(hLayout);

    this->show();
}
