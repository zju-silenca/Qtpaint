#include "setpen.h"
#include "ui_setpen.h"
#include "easycad.h"

setPen::setPen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setPen)
{
    ui->setupUi(this);
    QString tempS;
    ui->nowLineW->setText(tempS.setNum(defultLineW));
}

setPen::~setPen()
{

    delete ui;
}

void setPen::on_buttonBox_accepted()
{
    bool ok;
    QString tempStr;
    QString valueStr=ui->lineW->text();
    if(valueStr.toInt(&ok)<=0)//判断输入合法
        QMessageBox::warning(this,"Fail","请输入正确的参数");
    else
    {
        defultLineW=valueStr.toInt(&ok);
        QMessageBox::warning(this,"Success","设置成功");
        close();
    }
}

void setPen::on_buttonBox_rejected()
{
    close();
}
