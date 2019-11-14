#include "widget.h"

widget::widget(QWidget *parent) : QWidget(parent)
{
    this->setLayout(&layout);

    layout.addWidget(&button);
    size.setWidth(1);
    size.setHeight(1);

    connect(&button, SIGNAL(clicked()), this, SLOT(buttonClicked()));
}

void widget::buttonClicked()
{
    size.setWidth(2);
    widget* _button = new widget();
    layout.addWidget(_button);
}
