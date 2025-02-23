#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QLineEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow), num1(0), num2(0), result(0), secondNumber(false)
{
    ui->setupUi(this);

    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::onNumberButtonClicked);//1
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::onNumberButtonClicked);//2
    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::onNumberButtonClicked);//3
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::onNumberButtonClicked);//4
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::onNumberButtonClicked);//5
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::onNumberButtonClicked);//6
    connect(ui->pushButton_7, &QPushButton::clicked, this, &MainWindow::onNumberButtonClicked);//7
    connect(ui->pushButton_8, &QPushButton::clicked, this, &MainWindow::onNumberButtonClicked);//8
    connect(ui->pushButton_9, &QPushButton::clicked, this, &MainWindow::onNumberButtonClicked);//9)
    connect(ui->pushButton_10, &QPushButton::clicked, this, &MainWindow::onNumberButtonClicked);//0

    connect(ui->pushButton_11, &QPushButton::clicked, this, &MainWindow::onOperationButtonClicked); // +
    connect(ui->pushButton_12, &QPushButton::clicked, this, &MainWindow::onOperationButtonClicked); // -
    connect(ui->pushButton_13, &QPushButton::clicked, this, &MainWindow::onOperationButtonClicked); // *
    connect(ui->pushButton_14, &QPushButton::clicked, this, &MainWindow::onOperationButtonClicked); // /

    connect(ui->pushButton_15, &QPushButton::clicked, this, &MainWindow::onClearClicked);

    connect(ui->pushButton_16, &QPushButton::clicked, this, &MainWindow::onEnterClicked);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onNumberButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    QString buttonText = button->text();

    if (secondNumber) {
        ui->lineEdit_2->insert(buttonText);
    } else {
        ui->lineEdit->insert(buttonText);
    }
}

void MainWindow::onOperationButtonClicked()
{
    QPushButton *button = qobject_cast<QPushButton *>(sender());
    if (!button) return;

    currentOperation = button->text();

    secondNumber = true;
    ui->lineEdit_2->clear();
}

void MainWindow::onClearClicked()
{
    ui->lineEdit->clear();
    ui->lineEdit_2->clear();
    ui->lineEdit_3->clear();
    secondNumber = false;
}

void MainWindow::onEnterClicked()
{
    num1 = ui->lineEdit->text().toDouble();
    num2 = ui->lineEdit_2->text().toDouble();

    if (currentOperation == "+") {
        result = num1 + num2;
    } else if (currentOperation == "-") {
        result = num1 - num2;
    } else if (currentOperation == "*") {
        result = num1 * num2;
    } else if (currentOperation == "/") {
        if (num2 != 0) {
            result = num1 / num2;
        } else {
            ui->lineEdit_3->setText("Error: Division by zero");
            return;
        }
    }

    ui->lineEdit_3->setText(QString::number(result));

    secondNumber = false;
}


