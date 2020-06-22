#ifndef PICTURE_H
#define PICTURE_H

#include <QGraphicsPixmapItem>
#include <QFileDialog>
#include "shape.h"
#include "easycad.h"

class Picture : public Shape, public QGraphicsPixmapItem
{
public:
        Picture();

        void startDraw(QGraphicsSceneMouseEvent * event);
        void drawing(QGraphicsSceneMouseEvent * event);
        void selectable(int);
};

#endif // PICTURE_H
