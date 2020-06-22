#ifndef SETPICTURE_H
#define SETPICTURE_H

#include <QDialog>
#include "Picture.h"

namespace Ui {
class setPicture;
}

class setPicture : public QDialog
{
    Q_OBJECT

public:
    explicit setPicture(QWidget *parent = nullptr);
    ~setPicture();

private slots:

    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::setPicture *ui;
};

#endif // SETPICTURE_H
