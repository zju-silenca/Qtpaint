#include "paintWidget.h"
#include <QKeyEvent>
#include <QPainter>
#include <QGraphicsRectItem>


PaintWidget::PaintWidget(QWidget *parent)
        : QGraphicsScene(parent), currShapeCode(Shape::None), currItem(NULL), perm(false)
{

}


void PaintWidget::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    QGraphicsScene::mousePressEvent(event);

    if(currShapeCode==Shape::Eraser)//判断是否是橡皮擦工具
        iseraser=true;
    else
        iseraser=false;

    if (!event->isAccepted()){
        if (event->button() == Qt::LeftButton)//点击左键的动作
        {
            switch(currShapeCode)//判断当前绘制项目
        {
        case Shape::Line:
                {
                        Line *line = new Line;//创建新的Line对象指针
                        currItem = line;//绘制类型改为Line
                        addItem(line);//把Line对象添加到项目中
                        break;
                }
        /*case Shape::Rect://绘制矩形渲染有问题不用了
                {
                        Rect *rect = new Rect;
                        currItem = rect;
                        addItem(rect);
                        break;
                }*/
        case Shape::Oval://绘制椭圆
                {
                        Oval *oval = new Oval;
                        currItem = oval;
                        addItem(oval);
                        break;
                }
        case Shape::Picture://添加图片
                {
                        Picture *pic = new Picture;
                        currItem = pic;
                        addItem(pic);
                        break;
                }
        case Shape::Text://添加文本
                {
                        Text *text = new Text;
                        currItem = text;
                        addItem(text);
                        break;
                }
        case Shape::Eraser://橡皮擦
                {
                    currItem=NULL;
                    break;
                }
        case Shape::Select://选择工具
                {
                        currItem = NULL;
                        break;
                }
        }
            if(currItem) {
                currItem->startDraw(event);
                perm = false;
            }

        }

        /*本来是实现右键删除不过删不掉不用了
         * else if (event->button() == Qt::RightButton)
        {
            QGraphicsItem *itemToRemove = NULL;// 检测光标下是否有 item
                       foreach (QGraphicsItem *item, items(event->scenePos()))
                       {
                               itemToRemove = item;
                               break;
                       }
                       // 从 Scene 上移除 item
             if (itemToRemove != NULL&&!iseraser)
                    removeItem(itemToRemove);
        }*/
}

}

void PaintWidget::mouseMoveEvent(QGraphicsSceneMouseEvent *event)//鼠标移动事件
{
        if(currItem && !perm) {
                currItem->drawing(event);
        }
        QGraphicsScene::mouseMoveEvent(event);
}

void PaintWidget::keyPressEvent(QKeyEvent *event)//按下delete实现删除
{
    if (event->key() == Qt::Key_Delete&&iseraser) {
            // 移除所有选中的 items
            qDebug() << "selected items " << selectedItems().size();
            while (!selectedItems().isEmpty()) {
                removeItem(selectedItems().front());
            }
        } else {
            QGraphicsScene::keyPressEvent(event);
        }
}

void PaintWidget::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)//鼠标释放事件
{
        perm = true;
        QGraphicsScene::mouseReleaseEvent(event);
}










