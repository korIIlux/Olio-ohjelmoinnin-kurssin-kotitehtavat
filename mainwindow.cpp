#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    player1Time(120),
    player2Time(120),
    currentPlayer(1),
    gameRunning(false)
{
    ui->setupUi(this);

    ui->progressBar->setMaximum(120);
    ui->progressBar->setValue(120);
    ui->progressBar_2->setMaximum(120);
    ui->progressBar_2->setValue(120);

    connect(ui->pushButton_3, &QPushButton::clicked, this, &MainWindow::setTime120);
    connect(ui->pushButton_4, &QPushButton::clicked, this, &MainWindow::setTime300);
    connect(ui->pushButton_5, &QPushButton::clicked, this, &MainWindow::startGame);
    connect(ui->pushButton_6, &QPushButton::clicked, this, &MainWindow::stopGame);
    connect(ui->pushButton, &QPushButton::clicked, this, &MainWindow::switchPlayer);
    connect(ui->pushButton_2, &QPushButton::clicked, this, &MainWindow::switchPlayer);

    timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateTime);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setTime120()
{
    player1Time = player2Time = 120;
    ui->progressBar->setMaximum(120);
    ui->progressBar->setValue(120);
    ui->progressBar_2->setMaximum(120);
    ui->progressBar_2->setValue(120);
}

void MainWindow::setTime300()
{
    player1Time = player2Time = 300;
    ui->progressBar->setMaximum(300);
    ui->progressBar->setValue(300);
    ui->progressBar_2->setMaximum(300);
    ui->progressBar_2->setValue(300);
}

void MainWindow::startGame()
{
    if (gameRunning) return;

    gameRunning = true;
    timer->start(1000);

    ui->pushButton_5->setEnabled(false);
    ui->pushButton_6->setEnabled(true);
}

void MainWindow::stopGame()
{
    gameRunning = false;
    timer->stop();
    ui->pushButton_5->setEnabled(true);
    ui->pushButton_6->setEnabled(false);

    QMessageBox::information(this, "Game Over", "Game has been stopped.");
}

void MainWindow::switchPlayer()
{
    if (currentPlayer == 1) {
        currentPlayer = 2;
        ui->progressBar->setValue(player1Time);
        ui->progressBar_2->setValue(player2Time);
    } else {
        currentPlayer = 1;
        ui->progressBar_2->setValue(player2Time);
        ui->progressBar->setValue(player1Time);
    }
}

void MainWindow::updateTime()
{
    if (currentPlayer == 1) {
        player1Time--;
        ui->progressBar->setValue(player1Time);
    } else {
        player2Time--;
        ui->progressBar_2->setValue(player2Time);
    }

    if (player1Time <= 0 || player2Time <= 0) {
        gameRunning = false;
        timer->stop();
        QMessageBox::information(this, "Game Over", "Game Over! Time's up.");
        ui->pushButton_5->setEnabled(true);
        ui->pushButton_6->setEnabled(false);
    }
}
