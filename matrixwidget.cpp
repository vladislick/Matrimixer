#include "matrixwidget.h"

MatrixWidget::MatrixWidget(QWidget *parent) : QWidget(parent)
{
    /****** Let's create all needed stuff ******/

    matrixName = new QString();
    matrixSize = new QSize(1, 1);

    matrixNumbers = new QVector<QLineEdit*>();

    matrixMainLayout = new QVBoxLayout();
    matrixContentLayout = new QGridLayout();
    matrixSizeLayout = new QHBoxLayout();

    matrixNameLabel = new QLabel();
    matrixNameLabel->setAlignment(Qt::AlignCenter);
    matrixSizeLabel = new QLabel("x");

    //Setup the SpinBox of Width
    matrixWidthBox = new QSpinBox();
    matrixWidthBox->setMinimum(1);
    matrixWidthBox->setSingleStep(1);
    matrixWidthBox->setValue(1);
    matrixWidthBox->setAlignment(Qt::AlignCenter);

    //Setup the SpinBox of Height
    matrixHeightBox = new QSpinBox();
    matrixHeightBox->setMinimum(1);
    matrixHeightBox->setSingleStep(1);
    matrixHeightBox->setValue(1);
    matrixHeightBox->setAlignment(Qt::AlignCenter);

    //Setup Size Layout
    matrixSizeLayout->addStretch();
    matrixSizeLayout->addWidget(matrixWidthBox);
    matrixSizeLayout->addWidget(matrixSizeLabel);
    matrixSizeLayout->addWidget(matrixHeightBox);
    matrixSizeLayout->addStretch();

    //Add All Layouts to the Main Layout
    matrixMainLayout->addWidget(matrixNameLabel);
    matrixMainLayout->addLayout(matrixContentLayout);
    matrixMainLayout->addLayout(matrixSizeLayout);
    matrixMainLayout->addStretch();

    //Connect SpinBoxes of Size to Their Slots
    connect(matrixHeightBox, SIGNAL(valueChanged(int)), this, SLOT(matrixHeightChanged(int)));
    connect(matrixWidthBox, SIGNAL(valueChanged(int)), this, SLOT(matrixWidthChanged(int)));

    //Set Main Layout for the Matrix
    this->setLayout(matrixMainLayout);

    //Create This Matrix
    matrixSizeChanged();
}

void MatrixWidget::setName(QString name)
{
    *matrixName = name;
    matrixNameLabel->setText("<b>" + *matrixName + "</b>");
}

void MatrixWidget::setFont(QFont)
{

}

void MatrixWidget::setFontSize(int)
{

}

QString MatrixWidget::name()
{
    return *matrixName;
}

QFont MatrixWidget::font()
{

}

int MatrixWidget::fontSize()
{

}

void MatrixWidget::matrixHeightChanged(int value)
{
    matrixSize->setHeight(value);
    matrixSizeChanged();
}

void MatrixWidget::matrixWidthChanged(int value)
{
    matrixSize->setWidth(value);
    matrixSizeChanged();
}

MatrixWidget::~MatrixWidget()
{

}

void MatrixWidget::matrixSizeChanged()
{
    // Delete previous 'lineEdit' elements
    for (const auto& element : *matrixNumbers)
    {
        matrixMainLayout->removeWidget(element);
        delete element;
    }
    matrixNumbers->clear();

    //Create and setup new elements in matrix
    for (int x = 0; x < matrixSize->width(); x++)
    {
        for (int y = 0; y < matrixSize->height(); y++)
        {
            QLineEdit *elem = new QLineEdit();

            elem->setAlignment(Qt::AlignHCenter);
            elem->setPlaceholderText("0");
            elem->setSizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);

            matrixNumbers->append(elem);
            matrixContentLayout->addWidget(elem, y, x);
        }
    }
}
