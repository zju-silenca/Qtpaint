#ifndef SHAPE_H
#define SHAPE_H

#include <QtWidgets/QMainWindow>
#include <QtGui>
#include <QtWidgets>



class Shape
{
public:

        enum Code {
                None,
                Line,
                Oval,
                Rect,
                Picture,
                Select,
                Eraser,
                Text
        };


        Shape();

        virtual void startDraw(QGraphicsSceneMouseEvent * event) = 0;
        virtual void drawing(QGraphicsSceneMouseEvent * event) = 0;
        virtual void selectable(int) =0;




};

#endif // SHAPE_H
