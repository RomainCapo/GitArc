#include "gagame.h"
#include "gaviewgame.h"
#include "gahorizontalnotesbar.h"
#include "gagamerightpannel.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QSound>
#include <QMovie>


GAGame::GAGame(QWidget *parent) : QWidget(parent)
{
    this->raise();
    this->activateWindow();
    this->showFullScreen();

    QSound::play("..\\GitArc\\res\\sound\\NewLevel.wav");


    GAGameRightPannel *rightPannel = new GAGameRightPannel(this);

    QMovie *gif = new QMovie("..\\GitArc\\res\\img\\SnoopDogg.gif");
    QLabel *processLabel = new QLabel(this);
    processLabel->setMovie(gif);
    gif->start();

    QSize viewSize(this->width() * 3 / 5, this->height());//Part of the layout occupied by the view
    GAViewGame *gameView = new GAViewGame(viewSize, processLabel, rightPannel);

    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(processLabel);
    hLayout->setStretch(0, 1);
    hLayout->addWidget(gameView);
    hLayout->setStretch(1, 3);
    hLayout->addWidget(rightPannel);
    hLayout->setStretch(2, 1);

    hLayout->setSpacing(0);
    hLayout->setMargin(0);
    this->setLayout(hLayout);

    this->connect(rightPannel, &GAGameRightPannel::quitGameSig, this, &GAViewGame::close);

    this->show();
}

void GAGame::quitGame()
{
    this->close();
    GAMainMenu *gaMainMenu = new GAMainMenu();
}
