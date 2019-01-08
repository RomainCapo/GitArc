#include "gaviewgame.h"
#include "gaverticalnotes.h"
#include "gahorizontalnotesbar.h"
#include "ganote.h"
#include "ganotereader.h"
#include "constants.h"

#include <QGraphicsWidget>
#include <QDebug>
#include <QByteArray>
#include <QLabel>
#include <QPushButton>
#include <QHBoxLayout>
#include <QtMath>
#include <QMessageBox>
#include <QGraphicsTextItem>

GAViewGame::GAViewGame(QSize layoutSize, QWidget * _left, QWidget * _right, QGraphicsView *_parent) : QGraphicsView(_parent)
{
    this->scoreSaver = GAScore::get();

    this->setStyleSheet("QGraphicsView {background-color : white;}");

    //create list that contains notes
    this->strips = new QList<QList<GANote*>*>(); //contain the 4 note strip list
    strips->append(new QList<GANote*>());
    strips->append(new QList<GANote*>());
    strips->append(new QList<GANote*>());
    strips->append(new QList<GANote*>());

    this->score = 0;

    this->scene = new QGraphicsScene(this);
    this->setScene(this->scene);
    this->setSceneRect(0, 0, layoutSize.width(), layoutSize.height());

    this->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    this->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );

    //get right and left widget
    this->left = (QLabel*)_left;
    this->right = (GAGameRightPannel*)_right;

    //create horizonatal and vertical note bar
    this->verticalNotes = new GAVerticalNotes(sceneRect().width(), sceneRect().height());
    this->scene->addItem(this->verticalNotes);

    this->horizontalNotes = new GAHorizontalNotesBar(sceneRect().width(), sceneRect().height());
    this->scene->addItem(this->horizontalNotes);
    this->connect(this, &GAViewGame::wrongNotePlayed, this->horizontalNotes, &GAHorizontalNotesBar::wrongNotePlayed);

    //allow to read the note csv file note
    //GANoteReader *noteReader = new GANoteReader(":res/partitions/fes.csv");
    GANoteReader *noteReader = new GANoteReader("..\\GitArc\\res\\partitions\\randomPartition.csv");
    noteReader->generatePartition();
    noteReader->readPartition();
    this->connect(noteReader, &GANoteReader::nextNotesLine, this, &GAViewGame::drawNoteLine);

    gameTimer = new QTimer(this);
    gameTimer->setInterval(1000);
    this->connect(gameTimer, &QTimer::timeout, this, &GAViewGame::timerGame);

    this->show();
}

GAViewGame::~GAViewGame()
{
    delete this->verticalNotes;
    delete this->horizontalNotes;

    for(int i=0; i < this->strips->length(); i++)
    {
        delete this->strips->at(i);
    }
    delete this->strips;
}

void GAViewGame::keyPressEvent(QKeyEvent *event)
{
    static int totalCorrectNote = 0;

    int chordId = this->getChordId(event->key());
    if(chordId != -1)
       {
            horizontalNotes->highlightFret(chordId);

            //delete all the note outside the screen
            /*for(int i = 0; i < strips->size(); i++)
            {
                for(int j = 0; j < strips->at(i)->size(); j++)
                {
                    if(strips->at(i)->at(j)->y() >= horizontalNotes->noteBurner[0]->rect().y() + HEIGHT_NOTES_STRIP)
                    {
                        strips->at(i)->removeAt(j);
                    }
                }
            }*/


            if(!strips->at(chordId)->empty())
            {
                qreal rectTop = horizontalNotes->noteBurner[chordId]->rect().y();
                qreal noteY = strips->at(chordId)->first()->y();

                //detect if the note is inside the horizontal note bar
                if(noteY >= rectTop && noteY <= rectTop + HEIGHT_NOTES_STRIP)
                {
                    strips->at(chordId)->first()->setColor(QColor(76, 175, 80)); //set the note in green

                    result = (100 - qFabs((HEIGHT_NOTES_STRIP / 2) - (noteY - rectTop)));

                    score += result;

                    this->right->setScore(score);
                    strips->at(chordId)->removeFirst();
                    totalCorrectNote++;
                    this->right->setTotalCorrectNote(totalCorrectNote);
                }
                else
                {
                    score -= 50;
                    this->right->setScore(score);
                    emit this->wrongNotePlayed(chordId);
                }
            }
       }
}

void GAViewGame::keyReleaseEvent(QKeyEvent *event)
{
    int chordId = this->getChordId(event->key());
    if(chordId != -1)
            horizontalNotes->toBasicFret(chordId);
}

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
    return keyPressed;
}

void GAViewGame::drawNoteLine(QByteArray notesLine)
{
    static int totalNotes = 0;

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

            totalNotes++;
        }
    }

    this->right->setTotalNote(totalNotes);
}

void GAViewGame::timerGame()
{
    bool isEmptyList = true;

    for(int i = 0; i < strips->size(); i++)
    {
        for(int j = 0; j < strips->at(i)->size(); j++)
        {
            if(strips->at(i)->at(j)->y() >= horizontalNotes->noteBurner[0]->rect().y() + HEIGHT_NOTES_STRIP)
            {
                strips->at(i)->removeAt(j);
                //this->score -= 50;
            }

            if(!strips->at(i)->isEmpty())
            {
                isEmptyList = false;
            }
        }
    }

    if(isEmptyList)
    {
        gameTimer->stop();

        this->verticalNotes->hide();
        this->horizontalNotes->hide();
        this->right->hide();
        this->left->hide();

        this->setStyleSheet("QGraphicsView { background-color : rgb(79, 195, 247); }");


        endGame = new QGraphicsTextItem("End of the game !");
        scoreUser = new QGraphicsTextItem(QString("Your score : %1").arg(this->score));
        bestScoreEver = new QGraphicsTextItem(QString("Best score : %1").arg(this->scoreSaver->readBestScore()));

        endGame->setDefaultTextColor(QColor(250, 250, 250));
        scoreUser->setDefaultTextColor(QColor(250, 250, 250));
        bestScoreEver->setDefaultTextColor(QColor(250, 250, 250));

        endGame->setY(300);
        scoreUser->setY(450);
        bestScoreEver->setY(550);

        endGame->setFont(QFont("Times", 60, QFont::Bold));
        scoreUser->setFont(QFont("Times", 40, QFont::Bold));
        bestScoreEver->setFont(QFont("Times", 30, QFont::Bold));

        btnQuit = new QPushButton("Quit game");
        btnQuit->move(QPoint(0,700));
        this->connect(btnQuit, &QPushButton::clicked, this, &GAViewGame::closeGame);

        btnQuit->resize(QSize(250,60));
        btnQuit->setStyleSheet("QPushButton { background-color: transparent; border-radius: 15; border: 2 solid rgb(2, 119, 189); color: rgb(250, 250, 250); font-size: 25px; font-weight: bold;}"
                               "QPushButton:hover { background-color: rgb(129, 212, 250);}");

        btnBackToMenu = new QPushButton("Menu");
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
        this->scene->addItem(bestScoreEver);
        this->scene->addWidget(btnQuit);
        this->scene->addWidget(btnBackToMenu);
        this->scene->addItem(endText);

        this->scoreSaver->saveScore(this->score);
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

