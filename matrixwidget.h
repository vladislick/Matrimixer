#ifndef MATRIXWIDGET_H
#define MATRIXWIDGET_H

#include <QObject>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLineEdit>
#include <QLabel>
#include <QSpinBox>
#include <QString>
#include <QSize>
#include <QVector>
#include <QDebug>
#include <QPushButton>

class MatrixWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MatrixWidget(QWidget *parent = nullptr);
    ~MatrixWidget();

    //Set the Matrix Name
    void setName(QString);
    void setFont(QFont);
    void setFontSize(int);

    void heightAdjustable(bool);
    void widthAdjustable(bool);
    void adjustable(bool);
    void sizeVisible(bool);

    QString name();
    QFont   font();
    int     fontSize();

private:
    //Matrix Current Name
    QString     *matrixName;
    //Matrix Current Size (Width x Height)
    QSize       *matrixSize;

    //Matrix Cells
    QVector<QLineEdit*> *matrixNumbers;

    //Main Layout for Matrix (All elements shown vertical)
    QVBoxLayout *matrixMainLayout;
    //Matrix itself (QLineEdits only)
    QGridLayout *matrixContentLayout;
    //Field where user can read and change (if it is possible) matrix size
    QHBoxLayout *matrixSizeLayout;

    //Matrix Label for Name
    QLabel      *matrixNameLabel;
    //Matrix Label for Special Symbol in the Size Layout (like 'x' or any other)
    QLabel      *matrixSizeLabel;
    //Matrix Width SpinBox
    QSpinBox    *matrixWidthBox;
    //Matrix Height SpinBox
    QSpinBox    *matrixHeightBox;

    //Matrix Resize Handler
    void matrixSizeChanged();

private slots:
    //When SpinBox of Height was changed
    void matrixHeightChanged(int);
    //When SpinBox of Width was changed
    void matrixWidthChanged(int);
};

#endif // MATRIXWIDGET_H
