#include "gaviewgame.h"
#include "gaverticalnotes.h"
#include "gahorizontalnotesbar.h"
#include "ganotes.h"
#include "ganotereader.h"
#include "constants.h"
#include <QGraphicsWidget>
#include <QDebug>
#include <QByteArray>
#include <QMessageBox>

GAViewGame::GAViewGame(QSize layoutSize, QGraphicsView *parent) : QGraphicsView(parent)
{

    this->scene = new QGraphicsScene(this);
    this->setScene(this->scene);
    this->setSceneRect(0, 0, layoutSize.width(), layoutSize.height());

    this->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    this->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );


    this->mySceneRect = QRect(sceneRect().x(), sceneRect().y(), sceneRect().width(), sceneRect().height());

    verticalNotes = new GAVerticalNotes(this->mySceneRect);
    this->scene->addItem(verticalNotes);

    //horizontalNotes = new GAHorizontalNotesBar(this->mySceneRect);
    //this->scene->addItem(horizontalNotes);

    this->drawHorizontalRectangle(false, -1);

    GANoteReader *noteReader = new GANoteReader(":res/partitions/notes.csv");
    this->connect(noteReader, &GANoteReader::nextNotesLine, this, &GAViewGame::drawNoteLine);
    noteReader->readPartition();


    this->show();
}

void GAViewGame::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_A)
    {
        //horizontalNotes->isPressed(0);
        this->drawHorizontalRectangle(true, 0);
    }

    if(event->key() == Qt::Key_S)
    {
        //horizontalNotes->isPressed(1);
        this->drawHorizontalRectangle(true, 1);
    }

    if(event->key() == Qt::Key_D)
    {
        //horizontalNotes->isPressed(2);
        this->drawHorizontalRectangle(true, 2);
    }

    if(event->key() == Qt::Key_F)
    {
        //horizontalNotes->isPressed(3);
        this->drawHorizontalRectangle(true, 3);
    }
}

void GAViewGame::drawNoteLine(QByteArray notesLine)
{
    float stripWidth = this->sceneRect().width() / NUM_NOTES;
    float leftStripMargin = LEFTMARGIN_PERCENTAGE * stripWidth;
    for(int i = 0; i <= NUM_NOTES; i++)
    {
        if(notesLine[i] == '1'){
            float xPos = leftStripMargin + i * stripWidth / 2;
            GANotes *notes = new GANotes(QPointF(xPos - NOTE_RADIUS / 4, 0), this->sceneRect().height());
            this->scene->addItem(notes);
        }
    }
}

void GAViewGame::drawHorizontalRectangle(bool isClicked, int nbClic)
{
    for(int i = 0; i < NUM_NOTES; i++)
    {
        if(i == nbClic)
        {
            this->scene->addItem(new GAHorizontalNotesBar(i, isClicked, this->mySceneRect));
        }
        else
        {
            this->scene->addItem(new GAHorizontalNotesBar(i, false, this->mySceneRect));
        }
    }
}

