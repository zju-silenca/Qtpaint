#include "Text.h"

Text::Text()
{
    setFlag(QGraphicsItem::ItemIsMovable, true); //支持拖放
    setFlag(QGraphicsItem::ItemIsSelectable, true);//支持选中
}

void Text::startDraw(QGraphicsSceneMouseEvent * event)
{
    setTextInteractionFlags(Qt::TextEditorInteraction);//允许编辑
    setZValue(1000.0);
    setPlainText(tr("enter your text"));//默认的文字
}

void Text::drawing(QGraphicsSceneMouseEvent * event)
{
    setPos(event->scenePos());
}

void Text::selectable(int f)
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
