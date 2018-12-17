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

GAViewGame::GAViewGame(QSize layoutSize, QWidget * _left, QWidget * _right, QGraphicsView *parent) : QGraphicsView(parent)
{
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
    GANoteReader *noteReader = new GANoteReader(":res/partitions/fes.csv");
    noteReader->readPartition();
    this->connect(noteReader, &GANoteReader::nextNotesLine, this, &GAViewGame::drawNoteLine);


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
            horizontalNotes->isPressed(chordId);

            //delete all the note outside the screen
            for(int i = 0; i < strips->size(); i++)
            {
                for(int j = 0; j < strips->at(i)->size(); j++)
                {
                    if(strips->at(i)->at(j)->y() >= horizontalNotes->noteBurner[0]->rect().y() + HEIGHT_NOTES_STRIP)
                    {
                        strips->at(i)->removeAt(j);
                    }
                }
            }


            if(!strips->at(chordId)->empty())
            {
                qreal rectTop = horizontalNotes->noteBurner[chordId]->rect().y();
                qreal noteY = strips->at(chordId)->first()->y();

                //detect if the note is inside the horizontal note bar
                if(noteY >= rectTop && noteY <= rectTop + HEIGHT_NOTES_STRIP)
                {
                    strips->at(chordId)->first()->setColor(Qt::green);//set the note in red
                    score += 100;
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
            horizontalNotes->isReleased(chordId);
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
            totalNotes++;
        }
    }

    this->right->setTotalNote(totalNotes);
}

