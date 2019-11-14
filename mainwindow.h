#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSplitter>
#include <QLabel>
#include <QDebug>

#include "matrixwidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_comboBox_MainOperation_currentIndexChanged(int index);

private:
    QLabel label;
    QSplitter   *splitter1;
    QSplitter   *splitter2;
    MatrixWidget matrix1;
    MatrixWidget matrix2;
    MatrixWidget matrix3;

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
