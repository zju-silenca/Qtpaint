
//绘制直线
#include "Line.h"

Line::Line()
{
    setFlag(QGraphicsItem::ItemIsMovable, true); //支持拖放
    setFlag(QGraphicsItem::ItemIsSelectable, true);//支持选中
    setPen(QPen(Qt::black, defultLineW, Qt::SolidLine, Qt::RoundCap));//设置画笔
    QPainter::Antialiasing;//反走样
}

void Line::startDraw(QGraphicsSceneMouseEvent * event)
{
        setLine(QLineF(event->scenePos(), event->scenePos()));
}

void Line::drawing(QGraphicsSceneMouseEvent * event)
{
        QLineF newLine(line().p1(), event->scenePos());
        setLine(newLine);
}

void Line::selectable(int f)
{
    if(f)
    {
        setFlag(QGraphicsItem::ItemIsMovable, true); //支持拖放
        setFlag(QGraphicsItem::ItemIsSelectable, true);//支持选中
    }
    else
    {
        setFlag(QGraphicsItem::ItemIsMovable, false); //取消支持拖放
        setFlag(QGraphicsItem::ItemIsSelectable, false);//取消支持选中
    }
}
