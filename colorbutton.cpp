#include "colorbutton.h"

ColorButton::ColorButton(const QColor & color, QWidget *parent) :
    QPushButton(parent)
{
    currentColor = color;
    connect(this, SIGNAL(clicked()), this, SLOT(chooseColor()));
}

QColor ColorButton::getColor()
{
    return currentColor;
}

void ColorButton::changeColor(const QColor & color)
{
    currentColor = color;
    colorChanged(currentColor);
}

void ColorButton::chooseColor()
{
    changeColor(QColorDialog::getColor(currentColor, this));
}

void ColorButton::paintEvent(QPaintEvent *event)
{
    QPushButton::paintEvent(event);

    int colorPadding = 6;

    QRect rect = event->rect();
    QPainter painter( this );
    painter.setBrush( QBrush( currentColor ) );
    rect.adjust(colorPadding, colorPadding, -colorPadding, -colorPadding);
    painter.drawRect(rect);
}
