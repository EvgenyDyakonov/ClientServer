#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "form.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    f = new Form;
    f->show();
    connect(this, &MainWindow::main_signal, f, &Form::form_slot);
    connect(f, &Form::form_signal, this, &MainWindow::main_slot);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::main_slot(QString a)
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

void MainWindow::on_pushButton_clicked()
{
  //  emit main_signal(ui->lineEdit->text());
    QString massege = "Первый: - " + ui->lineEdit->text();
    emit main_signal(massege);
    main_slot(massege);
    ui->lineEdit->setText("");
}

