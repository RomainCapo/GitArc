#include "gahorizontalnotesbar.h"
#include "constants.h"
#include "ganote.h"
#include <QDebug>
#include <QSound>

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
}

void GAHorizontalNotesBar::isPressed(int keyPressed)
{
    static QBrush brushActivated(Qt::lightGray);
    this->noteBurner.at(keyPressed)->setBrush(brushActivated);

   QSound::play("..\\GitArc\\res\\sound\\ding.wav");
}

void GAHorizontalNotesBar::isReleased(int keyPressed)
{
    static QBrush brushDisactivated(Qt::darkGray);
    this->noteBurner.at(keyPressed)->setBrush(brushDisactivated);

    this->keyPressed.append(keyPressed);
}

int GAHorizontalNotesBar::score()
{
    return _score;
}
