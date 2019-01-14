#include "gagame.h"
#include "gamainmenu.h"
#include "gaviewgame.h"
#include "gahorizontalnotesbar.h"
#include "gagamerightpannel.h"
#include "gasettings.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QMovie>
#include <QMediaPlayer>

/**
* GAGame
* GAGame Constructor
*
* @param QGraphicsItem* parent : The QGraphicsItem used as parent
*/
GAGame::GAGame(QWidget *parent) : QWidget(parent)
{
    this->raise();//place this widget to the top of the parent widget's stack.
    this->activateWindow();
    this->showFullScreen();

    this->setStyleSheet("QWidget {background-color : rgb(79, 195, 247);}");

    QMediaPlayer *mainMusic = new QMediaPlayer();
    mainMusic->setMedia(QUrl::fromLocalFile("..\\GitArc\\res\\sound\\music" + QString::number(GASettings::musicId) + ".wav"));//get music id with GASettings class
    mainMusic->play();

    GAGameRightPannel *rightPannel = new GAGameRightPannel(this);

    //run the gif on the right panel, we use label and property setMovie() to display the gif
    QMovie *gif = new QMovie("..\\GitArc\\res\\img\\SnoopDogg.gif");
    QLabel *leftPanel = new QLabel(this);
    leftPanel->setMovie(gif);
    gif->start();

    QSize viewSize(this->width() * 3 / 5, this->height());//Part of the layout occupied by the view
    this->gameView = new GAViewGame(viewSize, leftPanel, rightPannel, mainMusic);

    //use de property setStretch to allow 1/5 to each panel and 3/5 to the game window
    QHBoxLayout *hLayout = new QHBoxLayout(this);
    hLayout->addWidget(leftPanel);
    hLayout->setStretch(0, 1);
    hLayout->addWidget(this->gameView);
    hLayout->setStretch(1, 3);
    hLayout->addWidget(rightPannel);
    hLayout->setStretch(2, 1);

    hLayout->setSpacing(0);
    hLayout->setMargin(0);
    this->setLayout(hLayout);

    this->connect(this->gameView, &GAViewGame::quitGameSig, this, &GAGame::close);
    this->connect(this->gameView, &GAViewGame::backToMenuSig, this, &GAGame::quitGame);

    this->show();

    QTimer::singleShot(1000, this, &GAGame::setMyFocus);
}

/**
* GAGame
* quit the game and redirect to the menu
*/
void GAGame::quitGame()
{
    this->close();
    GAMainMenu *gaMainMenu = new GAMainMenu();
    Q_UNUSED(gaMainMenu);//use the macro to disable warning
}

void GAGame::setMyFocus()
{
    this->activateWindow();
    this->gameView->setFocus(Qt::OtherFocusReason);
}
