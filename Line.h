#ifndef LINE_H
#define LINE_H

#include <QGraphicsLineItem>
#include "shape.h"
#include "easycad.h"
class Line : public Shape, public QGraphicsLineItem
{
public:
        Line();

        void startDraw(QGraphicsSceneMouseEvent * event);
        void drawing(QGraphicsSceneMouseEvent * event);
        void selectable(int);
};

#endif // LINE_H
