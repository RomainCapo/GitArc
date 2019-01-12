#include "gaverticalnotes.h"
#include "constants.h"
#include <QPen>

/**
* GAVerticalNotes
* GAVerticalNote's constructor
*
* @param const QRect widgetRect : Should be the graphic view's rect
* @param QGraphicsItem* parent : The QGraphicsItem used as parent
*/
GAVerticalNotes::GAVerticalNotes(const float sceneWidth, const float sceneHeight)
{
    float stripWidth = sceneWidth / NUM_NOTES;
    QPen pen(Qt::black, PEN_WIDTH);

    for(int i = 0; i < NUM_NOTES; i++){
        int x = stripWidth * ( i + 1) - 0.5 * stripWidth;
        QGraphicsLineItem *line = new QGraphicsLineItem(x, 0, x, sceneHeight, this);
        line->setPen(pen);
    }
}

