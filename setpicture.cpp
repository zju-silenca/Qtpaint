#include "setpicture.h"
#include "Picture.h"
#include "easycad.h"
#include "ui_setpicture.h"


setPicture::setPicture(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setPicture)
{
    ui->setupUi(this);
    //ui->maxH->text()=maxH;
    //ui->maxW->text()=maxW;
    QString tempS;
    ui->nowmaxH->setText(tempS.setNum(defultH));
    ui->nowmaxW->setText(tempS.setNum(defultW));

}

setPicture::~setPicture()
{
    delete ui;
}


void setPicture::on_buttonBox_accepted()
{
    bool ok;
    QString tempStr1,tempStr2;
        QString valueStr1=ui->maxH->text();
        QString valueStr2=ui->maxW->text();
        if(valueStr1.toInt(&ok)<=0||valueStr2.toInt(&ok)<=0)//判断输入合法
            QMessageBox::warning(this,"Fail","请输入正确的参数");
        else
        {
            defultH=valueStr1.toInt(&ok);
            defultW=valueStr2.toInt(&ok);
            QMessageBox::warning(this,"Success","设置成功");
            close();
        }
}

void setPicture::on_buttonBox_rejected()
{
    close();
}
