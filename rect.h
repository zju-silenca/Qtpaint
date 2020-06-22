#ifndef RECT_H
#define RECT_H

#include <QGraphicsRectItem>
#include "shape.h"
#include "easycad.h"

class Rect : public Shape, public QGraphicsRectItem
{
public:
        Rect();

        void startDraw(QGraphicsSceneMouseEvent * event);
        void drawing(QGraphicsSceneMouseEvent * event);
        void selectable(int);
};

#endif // RECT_H
