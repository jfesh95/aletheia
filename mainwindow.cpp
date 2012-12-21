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
    delete mdiArea;
    delete ui;
}

void MainWindow::subWindowClosed()
{
    if (autoTile)
        mdiArea->tileSubWindows();
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
    bw->setAttribute(Qt::WA_DeleteOnClose);
    connect(bw, SIGNAL(destroyed()), this, SLOT(subWindowClosed()));
    mdiArea->addSubWindow(bw);
    bw->show();
    if (autoTile == true)
        mdiArea->tileSubWindows();
}

void MainWindow::closeAllWindows()
{
    mdiArea->closeAllSubWindows();
}

void MainWindow::autoTileToggled(bool checked)
{
    if (checked)
        mdiArea->tileSubWindows();
    autoTile = checked;
}

void MainWindow::cascadeWindows()
{
    mdiArea->cascadeSubWindows();
}

void MainWindow::tileHorizontally()
{

}

void MainWindow::tileVertically()
{
    QList<QMdiSubWindow*> windows = mdiArea->subWindowList();
    int count = windows.count();
    if (count < 2)
    {
        mdiArea->tileSubWindows();
        return;
    }
    int wHeight = mdiArea->height() / count;
    int y = 0;
    for (int i = 0; i < count; i++)
    {
        QMdiSubWindow *window = windows.at(i);
        //->resize(mdiArea->width(), wHeight);
        windows.at(i)->move(0, y);
        y += wHeight;
    }
}
