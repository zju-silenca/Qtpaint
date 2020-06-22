#ifndef SETPEN_H
#define SETPEN_H

#include <QDialog>

namespace Ui {
class setPen;
}

class setPen : public QDialog
{
    Q_OBJECT

public:
    explicit setPen(QWidget *parent = nullptr);
    ~setPen();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::setPen *ui;
};

#endif // SETPEN_H
