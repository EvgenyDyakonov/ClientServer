#include "form.h"
#include "ui_form.h"

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
}

Form::~Form()
{
    delete ui;
}

void Form::form_slot(QString a)
{
    if(ui->label->text()=="")
    {
        ui->label->setText(a);
    }
    else
    {
        QString new_text = ui->label->text()+"\n"+a;
        ui->label->setText(new_text);
    }

}

void Form::on_pushButton_clicked()
{
    QString massege = "Второй: - " + ui->lineEdit->text();
    emit form_signal(massege);
    form_slot(massege);
    ui->lineEdit->setText("");
}

