#ifndef PAINTWIDGET_H
#define PAINTWIDGET_H

#include <QtGui>
#include <QDebug>
#include <QtWidgets>
#include <QGraphicsRectItem>
#include <QGraphicsScene>

#include "shape.h"
#include "Line.h"
#include "rect.h"
#include "Oval.h"
#include "Text.h"
#include "Picture.h"

class PaintWidget : public QGraphicsScene
{
        Q_OBJECT

public:
        PaintWidget(QWidget *parent = 0);
public slots:
        void setCurrentShape(Shape::Code s)
        {
                if(s != currShapeCode) {
                        currShapeCode = s;
                }
        }

protected:
        void mousePressEvent(QGraphicsSceneMouseEvent *event);
        void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
        void keyPressEvent(QKeyEvent *event) ;
private:
        Shape::Code currShapeCode;//绘图模式
        Shape *currItem;//正在绘制的项目
        bool iseraser=false;//是否允许删除对象
        bool perm;//是否绘制完毕
};



#endif // PAINTWIDGET_H
