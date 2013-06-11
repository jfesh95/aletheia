#ifndef COLORBUTTON_H
#define COLORBUTTON_H

#include <QtWidgets>

class ColorButton : public QPushButton
{
    Q_OBJECT
public:
    explicit ColorButton(const QColor & color = Qt::black, QWidget *parent = 0);
    QColor getColor();
    
signals:
    void colorChanged(QColor);

public slots:
    void changeColor(const QColor &);
    void chooseColor();
    void paintEvent(QPaintEvent *event);
    
private:
    QColor currentColor;
};

#endif // COLORBUTTON_H
