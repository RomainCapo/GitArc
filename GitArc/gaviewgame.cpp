#include "gaviewgame.h"
#include "gaverticalnotes.h"
#include "gahorizontalnotesbar.h"
#include "ganotes.h"
#include "ganotereader.h"
#include <QGraphicsWidget>

GAViewGame::GAViewGame(QSize layoutSize, QGraphicsView *parent) : QGraphicsView(parent)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    this->setScene(scene);
    this->setSceneRect(0, 0, layoutSize.width(), layoutSize.height());

    this->setHorizontalScrollBarPolicy( Qt::ScrollBarAlwaysOff );
    this->setVerticalScrollBarPolicy( Qt::ScrollBarAlwaysOff );

    QRect mySceneRect(sceneRect().x(), sceneRect().y(), sceneRect().width(), sceneRect().height());

    GAVerticalNotes *verticalNotes = new GAVerticalNotes(mySceneRect);
    scene->addItem(verticalNotes);

    GAHorizontalNotesBar *horizontalNotes = new GAHorizontalNotesBar(mySceneRect);
    scene->addItem(horizontalNotes);

//    GANotes *notes = new GANotes(mySceneRect);
//    scene->addItem(notes);

    GANoteReader noteReader;
    noteReader.readCSVNote(":res/partitions/notes.csv");

    this->show();
}
