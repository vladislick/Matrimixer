#ifndef MATRIX_H
#define MATRIX_H

#include <QWidget>
#include <QSize>
#include <QGridLayout>
#include <QBoxLayout>

class Matrix : public QWidget
{
    Q_OBJECT
public:
    explicit Matrix(QWidget *parent = nullptr);

private:
    QSize matrixSize;
    QVBoxLayout mainLayout;
    QGridLayout mainMatrix;

public slots:
    void matrixSizeChanged();
};

#endif // MATRIX_H
