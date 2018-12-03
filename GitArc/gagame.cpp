#include "gagame.h"
#include "gaviewgame.h"
#include <QHBoxLayout>
#include <QLabel>

GAGame::GAGame(QWidget *parent) : QWidget(parent)
{
    this->showFullScreen();

    QSize viewSize(this->width() * 3 / 5, this->height());//Part of the layout occupied by the view
    GAViewGame *gameView = new GAViewGame(viewSize);

    QLabel *lbScore = new QLabel(this);
    lbScore->setText("Score : 0");

    lbTemp = new QLabel(this);
    lbTemp->setText("Temporary");

    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(lbTemp);
    hLayout->setStretch(0, 1);
    hLayout->addWidget(gameView);
    hLayout->setStretch(1, 3);
    hLayout->addWidget(lbScore);
    hLayout->setStretch(2, 1);

    hLayout->setSpacing(0);
    hLayout->setMargin(0);
    this->setLayout(hLayout);

    this->show();
}
