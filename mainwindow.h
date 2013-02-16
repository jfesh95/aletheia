#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMdiArea"
#include "QMdiSubWindow"
#include "QList"
#include "biblewindow.h"
#include "aboutdialog.h"
#include "helpbrowser.h"
#include "preferencesdialog.h"
#include "settings.h"

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
    void subWindowClosed();
    void showPreferencesDialog();
    void showHelpBrowser();
    void showAboutDialog();
    void newBibleWindow();
    void closeAllWindows();
    void cascadeWindows();
    void autoTileToggled(bool);
    void tileHorizontally();
    void tileVertically();
    void preferencesDialogFinished(Settings);
    void print();

private:
    Ui::MainWindow *ui;
    QMdiArea *mdiArea;
    bool autoTile;
    struct Settings settings;
};

#endif // MAINWINDOW_H
