#include "gaviewgame.h"
#include "gaverticalnotes.h"
#include "gahorizontalnotesbar.h"
#include "ganote.h"
#include "gaconstants.h"
#include "gagamerightpannel.h"
#include "ganotereader.h"
#include "gascore.h"

#include <QGraphicsWidget>
#include <QDebug>
#include <QByteArray>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QtMath>
#include <QMessageBox>
#include <QGraphicsTextItem>
#include <QMediaPlayer>

/**
* GAViewGame
* GAViewGame Constructor
*
* @param Qsize layoutSize : size occupied by the view in the layout
* @param QWidget * _left : use to access to left informations panel
* @param QWidget * _left : use to access to right informations panel
* @param QMediaPlayer *_mainMusic : use to pause and play the main music of the game
* @param QGraphicsItem* _parent : The QGraphicsItem used as parent
*/
GAViewGame::GAViewGame(QSize layoutSize, QWidget * _left, QWidget * _right, QMediaPlayer *_mainMusic, QGraphicsView *_parent) : QGraphicsView(_parent)
{
    this->scoreSaver = GAScore::get();
    this->mainMusic = _mainMusic;
    this->isFirst = true;
    this->totalCorrectNotes = 0;
    this->totalNotes = 0;
    this->score = 0;
    this->isPaused = false;

    //get right and left widget
    this->left = (QLabel*)_left;
    this->right = (GAGameRightPannel*)_right;

    this->setStyleSheet("QGraphicsView {background-color : white;}");

    //create list that contains each strip notes
    this->strips = new QList<QList<GANote*>*>(); //contain the 4 note strip list
    strips->append(new QList<GANote*>());
    strips->append(new QList<GANote*>());
    strips->append(new QList<GANote*>());
    strips->append(new QList<GANote*>());

    this->scene = new QGraphicsScene(this);
    this->setScene(this->scene);
    this->setSceneRect(0, 0, layoutSize.width(), layoutSize.height());

    //delete scroll bar
    this->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    this->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );

    //create horizonatal and vertical note bar
    this->verticalNotes = new GAVerticalNotes(sceneRect().width(), sceneRect().height());
    this->scene->addItem(this->verticalNotes);

    this->horizontalNotes = new GAHorizontalNotesBar(sceneRect().width(), sceneRect().height());
    this->scene->addItem(this->horizontalNotes);

    //create a random partitions with generatePartition() and read them with readPartition()
    this->noteReader = new GANoteReader("..\\GitArc\\res\\partitions\\randomPartition.csv");
    this->noteReader->generatePartition();
    this->noteReader->readPartition();

    gameTimer = new QTimer(this);
    gameTimer->setInterval(1000);

    this->connect(gameTimer, &QTimer::timeout, this, &GAViewGame::timerGame);
    this->connect(this, &GAViewGame::wrongNotePlayed, this->horizontalNotes, &GAHorizontalNotesBar::wrongNotePlayed);
    this->connect(this->noteReader, &GANoteReader::nextNotesLine, this, &GAViewGame::drawNoteLine);

    this->connect(this, &GAViewGame::pauseGameSig, this, &GAViewGame::pauseGame);

    this->show();
}

GAViewGame::~GAViewGame()
{   
    delete this->right;
    delete this->left;

    delete this->bestScore;
    delete this->btnQuit;
    delete this->btnBackToMenu;
    delete this->scoreUser;
    delete this->endGame;
    delete this->endText;

    delete this->noteReader;
    delete this->mainMusic;

    delete this->verticalNotes;
    delete this->horizontalNotes;

    for(int i=0; i < this->strips->length(); i++)
    {
        delete this->strips->at(i);
    }
    delete this->strips;
}

/**
* GAViewGame
* GAViewGame keyPressEvent method
*
* @param QKeyEvent *event : key event of the view
*/
void GAViewGame::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Escape && !isPaused)
    {
        emit pauseGameSig();
        isPaused = true;
    }

    int chordId = this->getChordId(event->key());

    //an id with -1 value mean that any key is pressed
    if(chordId != -1)
       {
            horizontalNotes->highlightFret(chordId);

            //check if the strip contains notes
            if(!strips->at(chordId)->empty())
            {
                qreal rectTop = horizontalNotes->noteBurner[chordId]->rect().y();//y top coordinate of the horizontal note bar
                qreal noteY = strips->at(chordId)->first()->y();//y coordinate of the center of the note

                //detect if the note is inside the horizontal note bar when key is pressed
                if(noteY >= rectTop && noteY <= rectTop + HEIGHT_NOTES_STRIP)
                {
                    strips->at(chordId)->first()->setColor(QColor(76, 175, 80)); //set the note in green                   
                    strips->at(chordId)->removeFirst();//remove the burned note from the list

                    //update informations panel
                    score += 100;
                    this->right->setScore(score);

                    totalCorrectNotes++;
                    this->right->setTotalCorrectNote(totalCorrectNotes);
                }
                else if(noteY + NOTE_RADIUS >= rectTop && noteY - NOTE_RADIUS <= rectTop)//detect if the note is on the horizontal note bar top edge when key is pressed
                {
                    strips->at(chordId)->first()->setColor(QColor(230, 126, 34));//set the note in orange
                    strips->at(chordId)->removeFirst();//remove the burned note from the list

                    //update informations panel
                    result = (100 - qFabs((HEIGHT_NOTES_STRIP / 2) - ((noteY + NOTE_RADIUS)  - rectTop)));
                    score += result;
                    this->right->setScore(score);

                    totalCorrectNotes++;
                    this->right->setTotalCorrectNote(totalCorrectNotes);
                }
                else //detect if the note is not inside the horizontal note bar when key is pressed
                {
                    //update score
                    score -= 50;
                    this->right->setScore(score);

                    QSound::play("..\\GitArc\\res\\sound\\error.wav");// play error sound

                    emit this->wrongNotePlayed(chordId);
                }
            }
       }
}

/**
* GAViewGame
* GAViewGame keyReleaseEvent method, put the fret of the horizontal notes bar to basic color when the key is released
*
* @param QKeyEvent *event : key event of the view
*/
void GAViewGame::keyReleaseEvent(QKeyEvent *event)
{
    int chordId = this->getChordId(event->key());
    if(chordId != -1)
        horizontalNotes->toBasicFret(chordId);
}

void GAViewGame::pauseGame()
{
    this->mainMusic->pause();
    this->gameTimer->stop();
    this->noteReader->pauseLecture();
    for(int i = 0; i < this->strips->count(); i++)
    {
        QList<GANote*>* noteLine = this->strips->at(i);
        for(int j = 0; j < noteLine->count(); j++)
        {
            GANote* note = noteLine->at(j);
            note->pauseAnimation();
            note->hide();
        }
    }

    this->verticalNotes->hide();
    this->horizontalNotes->hide();
    this->right->hide();
    this->left->hide();
    this->setStyleSheet("QGraphicsView { background-color : rgb(79, 195, 247); }");

    pauseGameText = new QGraphicsTextItem(tr("Paused !"));
    currentScore = new QGraphicsTextItem(QString(tr("Your current score : %1")).arg(this->score));

    pauseGameText->setDefaultTextColor(QColor(250, 250, 250));
    currentScore->setDefaultTextColor(QColor(250, 250, 250));

    pauseGameText->setY(300);
    currentScore->setY(450);

    pauseGameText->setFont(QFont("Times", 60, QFont::Bold));
    currentScore->setFont(QFont("Times", 40, QFont::Bold));

    btnBackToGame = new QPushButton(tr("&Resume game"));
    btnBackToGame->move(QPoint(0,700));
    this->connect(btnBackToGame, &QPushButton::clicked, this, &GAViewGame::resumeGame);

    btnBackToGame->resize(QSize(250,60));
    btnBackToGame->setStyleSheet("QPushButton { background-color: transparent; border-radius: 15; border: 2 solid rgb(2, 119, 189); color: rgb(250, 250, 250); font-size: 25px; font-weight: bold;}"
                           "QPushButton:hover { background-color: rgb(129, 212, 250);}");

    btnBackMenuInPause = new QPushButton(tr("&Menu"));
    btnBackMenuInPause->move(QPoint(300,700));
    this->connect(btnBackMenuInPause, &QPushButton::clicked, this, &GAViewGame::toMenu);

    btnBackMenuInPause->resize(QSize(250,60));
    btnBackMenuInPause->setStyleSheet("QPushButton { background-color: transparent; border-radius: 15; border: 2 solid rgb(2, 119, 189); color: rgb(250, 250, 250); font-size: 25px; font-weight: bold;}"
                           "QPushButton:hover { background-color: rgb(129, 212, 250);}");

    endTextPause = new QGraphicsTextItem(tr("Game designed by : Capocasale Romain, Freiburghaus Jonas and Moulin Vincent - Projet P2 GitArc"));
    endTextPause->setY(800);
    endTextPause->setFont(QFont("Times", 15, QFont::Normal));
    endTextPause->setDefaultTextColor(QColor(250, 250, 250));

    this->scene->addItem(pauseGameText);
    this->scene->addItem(currentScore);
    this->scene->addWidget(btnBackToGame);
    this->scene->addWidget(btnBackMenuInPause);
    this->scene->addItem(endTextPause);
}

/**
* GAViewGame
*
* @param int eventKey : Qt id of the pressed key
* @return id of the pressed key
*/
int GAViewGame::getChordId(int eventKey)
{
    int keyPressed = -1;
    switch (eventKey)
    {
        case Qt::Key_A:
            keyPressed = 0;
            break;
        case Qt::Key_S:
            keyPressed = 1;
            break;
        case Qt::Key_D:
            keyPressed = 2;
            break;
        case Qt::Key_F:
            keyPressed = 3;
            break;
        default:
            break;
    }
    keyPressed = this->isPaused ? -1 : keyPressed;
    return keyPressed;
}

void GAViewGame::drawNoteLine(QByteArray notesLine)
{
    float stripWidth = this->sceneRect().width() / NUM_NOTES;
    float leftStripMargin = LEFTMARGIN_PERCENTAGE * stripWidth;
    for(int i = 0; i <= NUM_NOTES; i++)
    {
        if(notesLine[i] == '1'){
            float xPos = leftStripMargin + i * stripWidth / 2;
            GANote *notes = new GANote(QPointF(xPos - NOTE_RADIUS / 4, 0), this->sceneRect().height());
            this->strips->at(i)->append(notes);
            this->scene->addItem(notes);

            if(isFirst)
            {
                gameTimer->start();
                isFirst = false;
            }

            this->totalNotes++;
        }
    }

    this->right->setTotalNote(totalNotes);
}

void GAViewGame::displayEndGameMenu()
{
    this->isPaused = true;
    this->verticalNotes->hide();
    this->horizontalNotes->hide();
    this->right->hide();
    this->left->hide();

    this->setStyleSheet("QGraphicsView { background-color : rgb(79, 195, 247); }");


    endGame = new QGraphicsTextItem(tr("End of the game !"));
    scoreUser = new QGraphicsTextItem(QString(tr("Your score : %1")).arg(this->score));
    bestScore = new QGraphicsTextItem(QString(tr("Best score : %1")).arg(this->scoreSaver->getBestScore()));

    endGame->setDefaultTextColor(QColor(250, 250, 250));
    scoreUser->setDefaultTextColor(QColor(250, 250, 250));
    bestScore->setDefaultTextColor(QColor(250, 250, 250));

    endGame->setY(300);
    scoreUser->setY(450);
    bestScore->setY(550);

    endGame->setFont(QFont("Times", 60, QFont::Bold));
    scoreUser->setFont(QFont("Times", 40, QFont::Bold));
    bestScore->setFont(QFont("Times", 30, QFont::Bold));

    btnQuit = new QPushButton(tr("&Quit game"));
    btnQuit->move(QPoint(0,700));
    this->connect(btnQuit, &QPushButton::clicked, this, &GAViewGame::closeGame);

    btnQuit->resize(QSize(250,60));
    btnQuit->setStyleSheet("QPushButton { background-color: transparent; border-radius: 15; border: 2 solid rgb(2, 119, 189); color: rgb(250, 250, 250); font-size: 25px; font-weight: bold;}"
                           "QPushButton:hover { background-color: rgb(129, 212, 250);}");

    btnBackToMenu = new QPushButton(tr("&Menu"));
    btnBackToMenu->move(QPoint(300,700));
    this->connect(btnBackToMenu, &QPushButton::clicked, this, &GAViewGame::toMenu);

    btnBackToMenu->resize(QSize(250,60));
    btnBackToMenu->setStyleSheet("QPushButton { background-color: transparent; border-radius: 15; border: 2 solid rgb(2, 119, 189); color: rgb(250, 250, 250); font-size: 25px; font-weight: bold;}"
                           "QPushButton:hover { background-color: rgb(129, 212, 250);}");

    endText = new QGraphicsTextItem(tr("Game designed by : Capocasale Romain, Freiburghaus Jonas and Moulin Vincent - Projet P2 GitArc"));
    endText->setY(800);
    endText->setFont(QFont("Times", 15, QFont::Normal));
    endText->setDefaultTextColor(QColor(250, 250, 250));


    this->scene->addItem(endGame);
    this->scene->addItem(scoreUser);
    this->scene->addItem(bestScore);
    this->scene->addWidget(btnQuit);
    this->scene->addWidget(btnBackToMenu);
    this->scene->addItem(endText);
}

void GAViewGame::timerGame()
{
    bool isEmptyList = true;
    for(int i = 0; i < strips->size(); i++)
    {
        for(int j = 0; j < strips->at(i)->size(); j++)
        {
            //when the note is below the horizontal note bar
            if(strips->at(i)->at(j)->y() >= horizontalNotes->noteBurner[0]->rect().y() + HEIGHT_NOTES_STRIP)
            {
                strips->at(i)->removeAt(j);//remove the note from the list

                QSound::play("..\\GitArc\\res\\sound\\error.wav");//play error

                //update score
                this->score -= 20;
                this->right->setScore(score);
            }

            if(!strips->at(i)->isEmpty())
            {
                isEmptyList = false;
            }
        }
    }

    //correspond to the end of the game
    if(isEmptyList)
    {
        gameTimer->stop();

        this->scoreSaver->saveScore(this->score);

        //stop thge music and hide de widget
        this->mainMusic->stop();

        displayEndGameMenu();
    }
}

void GAViewGame::closeGame()
{
    emit quitGameSig();
}

void GAViewGame::toMenu()
{
    emit backToMenuSig();
}

void GAViewGame::resumeGame()
{
    this->scene->removeItem(pauseGameText);
    this->scene->removeItem(currentScore);
    this->scene->removeItem(endTextPause);
    this->btnBackMenuInPause->hide();
    this->btnBackToGame->hide();
    this->setStyleSheet("QGraphicsView { background-color : white; }");

    this->verticalNotes->show();
    this->horizontalNotes->show();
    this->right->show();
    this->left->show();

    this->mainMusic->play();
    this->gameTimer->start();
    this->noteReader->resumeLecture();
    for(int i = 0; i < this->strips->count(); i++)
    {
        QList<GANote*>* noteLine = this->strips->at(i);
        for(int j = 0; j < noteLine->count(); j++)
        {
            GANote* note = noteLine->at(j);
            note->resumeAnimation();
            note->show();
        }
    }

    isPaused = false;
}
