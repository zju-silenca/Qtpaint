#include "Picture.h"

Picture::Picture()
{
    setFlag(QGraphicsItem::ItemIsMovable, true); //支持拖放
    setFlag(QGraphicsItem::ItemIsSelectable, true);//支持选中
}

void Picture::startDraw(QGraphicsSceneMouseEvent * event)
{
    QString fileName = QFileDialog::getOpenFileName(nullptr,
                                                    ("open iamge"),                         //对话框名称
                                                    ".",                                    //默认打开文件位置“.”为exe文件目录 "/"为根目录
                                                    ("image files(*.jpg *.png *.bmp)"));    //文件筛选器
    QPixmap image(fileName);
    setPixmap(image.scaled(defultW,defultH, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    setPos(event->scenePos());
}

void Picture::drawing(QGraphicsSceneMouseEvent * event)
{
    setPos(event->scenePos());
}

void Picture::selectable(int f)
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
