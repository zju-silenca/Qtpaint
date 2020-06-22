#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_easycad.h"
#include "paintWidget.h"

#include <QList>
#include <shape.h>
#include "setpicture.h"
#include "setpen.h"
#include "about.h"

static int defultW=500,defultH=500;//图片的默认最大宽高
static int defultLineW=5;//默认线宽

class easyCAD : public QMainWindow
{
    Q_OBJECT

public:
    easyCAD(QWidget *parent = Q_NULLPTR);

private slots:

    void on_picture_triggered();

    void on_addoval_triggered();

    void on_line_triggered();

    void on_select_triggered();

    void on_about_triggered();

    void on_eraser_triggered();

    void on_addText_triggered();

    void on_save_triggered();

    void on_savexml_triggered();

    void on_picture_setting_triggered();

    void on_pen_setting_triggered();

    void on_rect_triggered();

    void on_help_triggered();


signals:
        void changeCurrentShape(Shape::Code newShape);

private:
    Ui::easyCADClass ui;

};
