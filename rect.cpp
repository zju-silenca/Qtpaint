#include "rect.h"

Rect::Rect()
{
    setFlag(QGraphicsItem::ItemIsMovable, true); //支持拖放
    setFlag(QGraphicsItem::ItemIsSelectable, true);//支持选中
    setPen(QPen(Qt::black, defultLineW, Qt::SolidLine, Qt::RoundCap));
    QPainter::Antialiasing;
}

void Rect::startDraw(QGraphicsSceneMouseEvent * event)
{
        setRect(QRectF(event->scenePos(), QSizeF(0, 0)));
}

void Rect::drawing(QGraphicsSceneMouseEvent * event)
{
        QRectF r(rect().topLeft(),
                         QSizeF(event->scenePos().x() - rect().topLeft().x(), event->scenePos().y() - rect().topLeft().y()));
        setRect(r);
}
void Rect::selectable(int f)
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
