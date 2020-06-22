#ifndef TEXT_H
#define TEXT_H

#include <QGraphicsTextItem>
#include "shape.h"

class Text : public Shape, public QGraphicsTextItem
{
public:
        Text();

        void startDraw(QGraphicsSceneMouseEvent * event);
        void drawing(QGraphicsSceneMouseEvent * event);
        void selectable(int);

};
#endif // TEXT_H
