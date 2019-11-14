#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->lineEditMatrixExpressions->hide();
    ui->labelNotice->hide();
    ui->labelResult->hide();
    ui->dockMatrices->hide();

    matrix1.setName("Matrix A");
    matrix2.setName("Matrix B");
    matrix3.setName("Result");

    splitter1 = new QSplitter(Qt::Horizontal);
    splitter1->addWidget(&matrix1);
    splitter1->addWidget(&matrix2);
    splitter1->setCollapsible(0, false);
    splitter1->setCollapsible(1, false);
    ui->layoutMain->addWidget(splitter1);

    splitter2 = new QSplitter(Qt::Horizontal);
    splitter2->addWidget(splitter1);
    splitter2->addWidget(&matrix3);
    splitter2->setCollapsible(0, false);
    splitter2->setCollapsible(1, false);
    ui->layoutMain->addWidget(splitter2);

    //ui->layoutMain->addWidget(&matrix1, 0);
    //ui->layoutMain->addWidget(&matrix2, 0);
    //ui->layoutMain->addWidget(&matrix3, 0);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_comboBox_MainOperation_currentIndexChanged(int index)
{
    const short comboBoxLastIndex = short(ui->comboBox_MainOperation->count()) - 1;
    ui->lineEditMatrixExpressions->setVisible(index == comboBoxLastIndex);
    ui->dockMatrices->setVisible(index == comboBoxLastIndex);
    ui->labelNotice->setVisible(index == comboBoxLastIndex);
    ui->labelResult->setVisible(index == comboBoxLastIndex);
}
