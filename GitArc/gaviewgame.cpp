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
    this->strips = new QList<QList<GANote*>*>();
    strips->append(new QList<GANote*>());
    strips->append(new QList<GANote*>());
    strips->append(new QList<GANote*>());
    strips->append(new QList<GANote*>());

    this->scene = new QGraphicsScene(this);
    this->setScene(this->scene);
    this->setSceneRect(0, 0, layoutSize.width(), layoutSize.height());

    this->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    this->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );

    this->left = (QLabel*)_left;
    this->right = (QLabel*)_right;


    this->mySceneRect = QRect(sceneRect().x(), sceneRect().y(), sceneRect().width(), sceneRect().height());

    //verticalNotes = new GAVerticalNotes(this->mySceneRect.width(), this->mySceneRect.height());
    //this->scene->addItem(verticalNotes);

    horizontalNotes = new GAHorizontalNotesBar(this->mySceneRect.width(), this->mySceneRect.height());
    this->scene->addItem(horizontalNotes);

    GANoteReader *noteReader = new GANoteReader(":res/partitions/fes.csv");
    this->connect(noteReader, &GANoteReader::nextNotesLine, this, &GAViewGame::drawNoteLine);

    noteReader->readPartition();



    this->show();
}

void GAViewGame::keyPressEvent(QKeyEvent *event)
{
    int chordId = this->getChordId(event->key());
    if(chordId != -1)
       {
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

            horizontalNotes->isPressed(chordId);
            right->setText("Score : " + QString::number(horizontalNotes->score()));

            if(!strips->at(chordId)->empty())
            {
                qreal rectTop = horizontalNotes->noteBurner[chordId]->rect().y();
                qreal noteY = strips->at(chordId)->first()->y();

                if(noteY >= rectTop && noteY <= rectTop + HEIGHT_NOTES_STRIP)
                {
                    qDebug() << "collision : " << chordId;
                }

                if(noteY >= rectTop + HEIGHT_NOTES_STRIP )
                {
                    qDebug() << "delete";
                    strips->at(chordId)->removeFirst();
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
    float stripWidth = this->sceneRect().width() / NUM_NOTES;
    float leftStripMargin = LEFTMARGIN_PERCENTAGE * stripWidth;
    for(int i = 0; i <= NUM_NOTES; i++)
    {
        if(notesLine[i] == '1'){
            float xPos = leftStripMargin + i * stripWidth / 2;
            GANote *notes = new GANote(QPointF(xPos - NOTE_RADIUS / 4, 0), this->sceneRect().height());
            this->strips->at(i)->append(notes);
            this->scene->addItem(notes);
        }
    }
}

