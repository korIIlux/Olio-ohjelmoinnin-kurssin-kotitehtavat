#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onNumberButtonClicked();
    void onOperationButtonClicked();
    void onClearClicked();
    void onEnterClicked();

private:
    Ui::MainWindow *ui;
    double num1, num2, result;
    QString currentOperation;
    bool secondNumber;
};

#endif // MAINWINDOW_H
