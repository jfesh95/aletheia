#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showMaximized();

    mdiArea = new QMdiArea(this);
    setCentralWidget(mdiArea);

    autoTile = true;

    newBibleWindow();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showPreferencesDialog()
{
    PreferencesDialog *pd = new PreferencesDialog(this);
    pd->show();
}

void MainWindow::showAboutDialog()
{
    AboutDialog *ad = new AboutDialog(this);
    ad->show();
}

void MainWindow::newBibleWindow()
{
    BibleWindow *bw = new BibleWindow();
    mdiArea->addSubWindow(bw);
    bw->show();
    if (autoTile == true)
        mdiArea->tileSubWindows();
}
