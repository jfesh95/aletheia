#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QDialog>
#include <QColor>
#include <QFont>
#include "colorbutton.h"

namespace Ui {
class PreferencesDialog;
}

class PreferencesDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit PreferencesDialog(QWidget *parent = 0);
    ~PreferencesDialog();
    QFont getFont();
    QColor getFontColor();
    QColor getBackgroundColor();

public slots:
    void changeFontFamily(QFont);
    void changeFontSize(int);
    void changeFontColor(QColor);
    void changeBackgroundColor(QColor);
    
private:
    void updateSample();
    Ui::PreferencesDialog *ui;
    ColorButton *fontColorButton;
    ColorButton *backgroundColorButton;
    QFont font;
    QColor fontColor;
    QColor backgroundColor;
};

#endif // PREFERENCESDIALOG_H
