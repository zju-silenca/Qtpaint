#ifndef OVAL_H
#define OVAL_H
#include <QGraphicsEllipseItem>
#include "shape.h"
#include "easycad.h"
class Oval : public Shape, public QGraphicsEllipseItem
{
public:
        Oval();

        void startDraw(QGraphicsSceneMouseEvent * event);
        void drawing(QGraphicsSceneMouseEvent * event);
        void selectable(int);
};
#endif // OVAL_H
