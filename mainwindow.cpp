#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    count(0)
{
    ui->setupUi(this);


    ui->pushButton->disconnect();
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::on_pushButton_clicked);

    ui->pushButton_2->disconnect();
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::on_pushButton_2_clicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    count++;
    ui->lineEdit->setText(QString::number(count));
}

void MainWindow::on_pushButton_2_clicked()
{
    count = 0; // Сброс счётчика
    ui->lineEdit->setText(QString::number(count));
}
