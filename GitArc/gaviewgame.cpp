#include "gaviewgame.h"
#include "gaverticalnotes.h"
#include "gahorizontalnotesbar.h"
#include "ganotes.h"
#include "ganotereader.h"
#include "constants.h"
#include <QGraphicsWidget>
#include <QDebug>
#include <QByteArray>

GAViewGame::GAViewGame(QSize layoutSize, QGraphicsView *parent) : QGraphicsView(parent)
{
    this->scene = new QGraphicsScene(this);
    this->setScene(this->scene);
    this->setSceneRect(0, 0, layoutSize.width(), layoutSize.height());

    this->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    this->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );

    this->mySceneRect = QRect(sceneRect().x(), sceneRect().y(), sceneRect().width(), sceneRect().height());

    GAVerticalNotes *verticalNotes = new GAVerticalNotes(this->mySceneRect);
    this->scene->addItem(verticalNotes);

    GAHorizontalNotesBar *horizontalNotes = new GAHorizontalNotesBar(this->mySceneRect);
    this->scene->addItem(horizontalNotes);

    GANoteReader *noteReader = new GANoteReader(":res/partitions/notes.csv");
    this->connect(noteReader, &GANoteReader::nextNotesLine, this, &GAViewGame::drawNoteLine);
    noteReader->readPartition();

    this->show();
}

void GAViewGame::drawNoteLine(QByteArray notesLine)
{
    for(int i = 0; i <= NUM_NOTES; i++)
    {
        if(notesLine[i] != 0){
            GANotes *notes = new GANotes(this->mySceneRect, i);
            this->scene->addItem(notes);
        }
    }
}

