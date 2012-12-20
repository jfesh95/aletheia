#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMdiArea>
#include "biblewindow.h"
#include "aboutdialog.h"
#include "preferencesdialog.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    
private slots:
    void showPreferencesDialog();

    void showAboutDialog();

    void newBibleWindow();

private:
    Ui::MainWindow *ui;
    QMdiArea *mdiArea;
    bool autoTile;
};

#endif // MAINWINDOW_H
