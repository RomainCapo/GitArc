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
    this->bellSound = new QSound("..\\GitArc\\res\\sound\\ding.wav");

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

    this->bellSound->play();
}

void GAHorizontalNotesBar::isReleased(int keyPressed)
{
    static QBrush brushDisactivated(Qt::darkGray);
    this->noteBurner.at(keyPressed)->setBrush(brushDisactivated);
}

void GAHorizontalNotesBar::wrongNotePlayed(int keyPressed)
{
    static QBrush brushFail(Qt::red);
    this->noteBurner.at(keyPressed)->setBrush(brushFail);

    QTimer *changeColorTimer = new QTimer(this);
    changeColorTimer->setInterval(500);
    changeColorTimer->setSingleShot(true);
    this->connect(changeColorTimer,  &QTimer::timeout, this, [&keyPressed, this]() -> void {
        this->isReleased(keyPressed);
    });
}

