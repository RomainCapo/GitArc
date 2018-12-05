#include "gahorizontalnotesbar.h"
#include "constants.h"
#include "ganotes.h"
#include <QDebug>

/**
* GAHorizontalNotesBar
* GAHorizontalNotesBar's constructor
*
* @param const QRect widgetRect : Should be the graphic view's rect
* @param QGraphicsItem* parent : The QGraphicsItem used as parent
*/
GAHorizontalNotesBar::GAHorizontalNotesBar(const float sceneWidth, const float sceneHeight) : sceneWidth(sceneWidth), sceneHeight(sceneHeight)
{
    float stripWidth = sceneWidth / NUM_NOTES;
    QPen pen(Qt::black, PEN_WIDTH);
    QBrush brush(Qt::darkGray);

    for(int i = 0; i < NUM_NOTES; i++)
    {
        float ox = stripWidth * i;
        QGraphicsRectItem *rect = new QGraphicsRectItem(QRectF(ox, sceneHeight - HEIGHT_NOTES_STRIP, stripWidth, HEIGHT_NOTES_STRIP), this);
        rect->setPen(pen);
        rect->setBrush(brush);
        this->noteBurner.append(rect);
    }

    this->timerCollision = new QTimer(this);
    this->connect(this->timerCollision, &QTimer::timeout, this, &GAHorizontalNotesBar::checkNoteCollision);
    // FIXME : variable magique
    this->timerCollision->start(100);
}

void GAHorizontalNotesBar::isPressed(int keyPressed)
{
    static QBrush brushActivated(Qt::lightGray);
    this->noteBurner.at(keyPressed)->setBrush(brushActivated);
}

void GAHorizontalNotesBar::isReleased(int keyPressed)
{
    static QBrush brushDisactivated(Qt::darkGray);
    this->noteBurner.at(keyPressed)->setBrush(brushDisactivated);
}

// TODO : A supprimer
QRectF GAHorizontalNotesBar::boundingRect() const
{
    return QRectF(0, sceneHeight - HEIGHT_NOTES_STRIP, this->sceneWidth, HEIGHT_NOTES_STRIP);
}

void GAHorizontalNotesBar::checkNoteCollision()
{
    for(QGraphicsRectItem *noteChord : this->noteBurner)
    {
        QList<QGraphicsItem*> collidingItems = noteChord->collidingItems(Qt::IntersectsItemBoundingRect);
        for(QGraphicsItem *collidingItem : collidingItems)
        {
            GANotes *note = dynamic_cast<GANotes *>(collidingItem);
            if(note)
                qDebug() << "Collision detected";
            // qDebug() << collidingItem->boundingRect();
            // qDebug() << collidingItem->x();
        }
    }
}
