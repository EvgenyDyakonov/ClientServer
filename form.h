#ifndef FORM_H
#define FORM_H

#include <QWidget>

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:
    explicit Form(QWidget *parent = nullptr);
    ~Form();

private:
    Ui::Form *ui;

public slots:
    void form_slot(QString a);

signals:
    void form_signal(QString);
private slots:
    void on_pushButton_clicked();
};

#endif // FORM_H
