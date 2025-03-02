#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProgressBar>
#include <QPushButton>
#include <QTimer>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void setTime120();
    void setTime300();
    void startGame();
    void stopGame();
    void switchPlayer();
    void updateTime();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    int player1Time;
    int player2Time;
    int currentPlayer;
    bool gameRunning;
};

#endif // MAINWINDOW_H
