#include "gaviewgame.h"
#include "gaverticalnotes.h"
#include "gahorizontalnotesbar.h"
#include <QGraphicsLinearLayout>
#include <QGraphicsWidget>

GAViewGame::GAViewGame(QGraphicsView *parent) : QGraphicsView(parent)
{
    this->showFullScreen();
    this->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    this->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    QGraphicsScene *scene = new QGraphicsScene(this);
    this->setScene(scene);

    GAVerticalNotes *verticalNotes = new GAVerticalNotes(this->rect());
    scene->addItem(verticalNotes);

    GAHorizontalNotesBar *horizontalNotes = new GAHorizontalNotesBar(this->rect());
    scene->addItem(horizontalNotes);

    QGraphicsLinearLayout *vLayout = new QGraphicsLinearLayout(Qt::Vertical);
    vLayout->addItem(verticalNotes);
    vLayout->addItem(horizontalNotes);

    QGraphicsLinearLayout *hLayout = new QGraphicsLinearLayout(Qt::Horizontal);
    hLayout->addItem(vLayout);
    hLayout->addItem(vLayout);
    hLayout->addItem(vLayout);

    QGraphicsWidget* container = new QGraphicsWidget();
    container->setLayout(hLayout);
    scene->addItem(container);

    this->show();
}
