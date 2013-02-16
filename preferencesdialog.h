#ifndef PREFERENCESDIALOG_H
#define PREFERENCESDIALOG_H

#include <QDialog>
#include <QColor>
#include <QFont>
#include "colorbutton.h"
#include "settings.h"

namespace Ui {
class PreferencesDialog;
}

class PreferencesDialog : public QDialog
{
    Q_OBJECT
    
public:
    explicit PreferencesDialog(struct Settings _settings, QWidget *parent = 0);
    ~PreferencesDialog();

signals:
    void dialogFinished(struct Settings);

public slots:
    void changeFontFamily(QFont);
    void changeFontSize(int);
    void changeFontColor(QColor);
    void changeBackgroundColor(QColor);
    
private slots:
    void on_buttonBox_accepted();
    void styleChanged(QString style);
    void on_buttonBox_clicked(QAbstractButton *button);

private:
    void updateSample();
    Ui::PreferencesDialog *ui;
    ColorButton *fontColorButton;
    ColorButton *backgroundColorButton;
    struct Settings settings;
};

#endif // PREFERENCESDIALOG_H
