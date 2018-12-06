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
GAHorizontalNotesBar::GAHorizontalNotesBar(const float _sceneWidth, const float _sceneHeight): sceneWidth(_sceneWidth), sceneHeight(_sceneHeight)
{
    this->_score = 0;
    stripWidth = sceneWidth / NUM_NOTES;
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




    for(int i = 0; i < noteBurner.size(); i++)
    {
        QList<QGraphicsItem*> collidingItems = noteBurner[i]->collidingItems(Qt::IntersectsItemBoundingRect);
        for(QGraphicsItem *collidingItem : collidingItems)
        {
            GANotes *note = dynamic_cast<GANotes *>(collidingItem);
            if(note)
            {
                qDebug() << "keyPressed : " << keyPressed << " i : " << i;
                    if(keyPressed == i && note->y() > sceneHeight - HEIGHT_NOTES_STRIP && note->y() < sceneHeight)
                    {
                        qDebug() << "collision on touche : " << i;
                        _score += 10;
                        qDebug() << score();
                    }
            }
        }
    }

    this->keyPressed.append(keyPressed);
}

void GAHorizontalNotesBar::isReleased(int keyPressed)
{
    static QBrush brushDisactivated(Qt::darkGray);
    this->noteBurner.at(keyPressed)->setBrush(brushDisactivated);

    this->keyPressed.append(keyPressed);
}

void GAHorizontalNotesBar::checkNoteCollision()
{
    //qDebug() << this->score();
   /* for(int i = 0; i < noteBurner.size(); i++)
    {
        QList<QGraphicsItem*> collidingItems = noteBurner[i]->collidingItems(Qt::IntersectsItemBoundingRect);
        for(QGraphicsItem *collidingItem : collidingItems)
        {
            GANotes *note = dynamic_cast<GANotes *>(collidingItem);
            if(note)
            {
                if(!keyPressed.empty())
                {
                    if(keyPressed.contains(i) && note->y() > sceneHeight - HEIGHT_NOTES_STRIP && note->y() < sceneHeight)
                    {
                        qDebug() << "collision on touche : " << i;
                    }
                }
            }
        }
    }*/
}

int GAHorizontalNotesBar::score()
{
    return _score;
}
