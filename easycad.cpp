
//主窗口
#include "easycad.h"
#include <QDialog>
#include "paintWidget.h"
#include <QMessageBox>
#include <QActionGroup>
#include <QFileDialog>
#include <QImage>
#include <QBitmap>

easyCAD::easyCAD(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    QActionGroup *actionGroup = new QActionGroup(this);//创建活动组，使工具栏的每个按钮互斥
    actionGroup->addAction(ui.line);
    actionGroup->addAction(ui.eraser);
    actionGroup->addAction(ui.addText);
    actionGroup->addAction(ui.select);
    actionGroup->addAction(ui.addoval);
    actionGroup->addAction(ui.picture);
    actionGroup->addAction(ui.rect);

    PaintWidget *paintWidget = new PaintWidget(this);
    ui.paintArea = new QGraphicsView(paintWidget, this);
    setCentralWidget(ui.paintArea);//创建绘图区

    connect(this, SIGNAL(changeCurrentShape(Shape::Code)),paintWidget, SLOT(setCurrentShape(Shape::Code)));
    //连接画笔种类的改变信号给修改图形的槽

    ui.statusBar->showMessage("欢迎使用(*^▽^*)");//初始化状态栏
}



void easyCAD::on_picture_triggered()//点击添加图片的动作
{
    emit changeCurrentShape(Shape::Picture);
    ui.statusBar->showMessage("已选中:图片工具");
}

void easyCAD::on_addoval_triggered()//点击椭圆的动作
{
    ui.statusBar->showMessage("已选中:椭圆工具");
    emit changeCurrentShape(Shape::Oval);
}

void easyCAD::on_line_triggered()//点击直线的动作
{
    emit changeCurrentShape(Shape::Line);
    ui.statusBar->showMessage("已选中:直线工具");
}

void easyCAD::on_rect_triggered()
{
    emit changeCurrentShape(Shape::Rect);
    ui.statusBar->showMessage("已选中:矩形工具");
}

void easyCAD::on_select_triggered()//点击选择工具的动作
{
    emit changeCurrentShape(Shape::Select);
    ui.statusBar->showMessage("已选中:选择工具");

}

void easyCAD::on_about_triggered()
{
    QMessageBox::about(NULL, "关于", "Created by QT");
}

void easyCAD::on_eraser_triggered()
{
    emit changeCurrentShape(Shape::Eraser);
    ui.statusBar->showMessage("已选中:消除工具");
}

void easyCAD::on_addText_triggered()
{
    emit changeCurrentShape(Shape::Text);
    ui.statusBar->showMessage("已选中:文本工具");
}

void easyCAD::on_save_triggered()//保存为图片
{
    QString fileName1 = QFileDialog::getSaveFileName(this,tr("Save Image"),"./defult.png",tr("Images (*.png *.bmp *.jpg)")); //选择路径
    QPixmap pixMap= QPixmap::grabWidget(ui.paintArea);
    pixMap.save(fileName1);
    QMessageBox::warning(this,"Success","成功保存图片");
}

void easyCAD::on_savexml_triggered()//保存为xml
{
    QString fileName(QFileDialog::getSaveFileName(this,tr("Save Xml"),"./defult.xml",tr("Xml (*.xml)")));
        QFile file(fileName);
        if (!file.open(QIODevice::WriteOnly))
        {
                return;
        }
        QXmlStreamWriter xmlWriter(&file);
        xmlWriter.setAutoFormatting(true);
        xmlWriter.writeStartDocument();
        xmlWriter.writeStartElement("SceneData");
        xmlWriter.writeAttribute("version", "v1.0");
        xmlWriter.writeStartElement("GraphicsItemList");
        foreach( QGraphicsItem* item, ui.paintArea->items())
        {
            if( item->type() == QGraphicsItem::Type )
            {
                QGraphicsItem* myItem = (QGraphicsItem*)item;
                xmlWriter.writeStartElement("MyGraphicsItem");
                xmlWriter.writeAttribute("xCoord", QString::number(myItem->x()));
                xmlWriter.writeAttribute("yCoord", QString::number(myItem->y()));
                xmlWriter.writeEndElement();  //end of MyGraphicsItem
            }
        }
        xmlWriter.writeEndElement();   //end of GraphicsItemList
        xmlWriter.writeEndElement();   //end of SceneData
        QMessageBox::warning(this,"Success","成功保存文档");
}

void easyCAD::on_picture_setting_triggered()
{
    QDialog *dialog = new setPicture(this);
    dialog->show();
}

void easyCAD::on_pen_setting_triggered()
{
    QDialog *dialog = new setPen(this);
    dialog->show();
}


void easyCAD::on_help_triggered()
{
    QDialog *dialog = new About(this);
    dialog->show();
}


