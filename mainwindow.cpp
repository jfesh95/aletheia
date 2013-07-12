#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QPrinter>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    showMaximized();

    mdiArea = new QMdiArea(this);
    setCentralWidget(mdiArea);

    autoTile = true;

    // Lest use the best font available
    QFontDatabase fd;
    QStringList fonts = fd.families();
    if (fonts.contains("LM Sans 10", Qt::CaseInsensitive))
        settings.font = QFont("LM Sans 10", 13);
    else if (fonts.contains("Latin Modern Sans", Qt::CaseInsensitive))
        settings.font = QFont("Latin Modern Sans", 13);
    else if (fonts.contains("Cantarell", Qt::CaseInsensitive))
        settings.font = QFont("Cantarell", 13);
    else if (fonts.contains("Sawasdee", Qt::CaseInsensitive))
        settings.font = QFont("Sawasdee", 13);
    else if (fonts.contains("Candara", Qt::CaseInsensitive))
        settings.font = QFont("Candara", 13);
    else if (fonts.contains("Calibri Light", Qt::CaseInsensitive))
        settings.font = QFont("Calibri Light", 13);
    else if (fonts.contains("Calibri", Qt::CaseInsensitive))
        settings.font = QFont("Calibri", 13);
    else if (fonts.contains("Verdana", Qt::CaseInsensitive))
        settings.font = QFont("Verdana", 13);
    else if (fonts.contains("Georgia", Qt::CaseInsensitive))
        settings.font = QFont("Georgia", 13);
    else settings.font = QFont("serif");
    settings.font.setStyleHint(QFont::Serif);

    settings.fontColor = Qt::black;
    settings.backgroundColor = Qt::white;
    settings.showCrossrefs = false;

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
    PreferencesDialog *pd = new PreferencesDialog(settings, this);
    pd->show();
    connect(pd, SIGNAL(dialogFinished(struct Settings)), this, SLOT(preferencesDialogFinished(struct Settings)));
}

void MainWindow::preferencesDialogFinished(struct Settings _settings)
{
    settings = _settings;

    QList<QMdiSubWindow*> windowList = mdiArea->subWindowList();
    for (int i = 0; i < windowList.length(); i++)
    {
        qobject_cast<BibleWindow*>(windowList[i]->widget())->setTextFont(settings.font);
        qobject_cast<BibleWindow*>(windowList[i]->widget())->setTextFontColor(settings.fontColor);
        qobject_cast<BibleWindow*>(windowList[i]->widget())->setTextBackgroundColor(settings.backgroundColor);
        qobject_cast<BibleWindow*>(windowList[i]->widget())->setShowCrossReferences(settings.showCrossrefs);
    }
}

void MainWindow::showHelpBrowser()
{
    HelpBrowser *hb = new HelpBrowser(this);
    hb->show();
}

void MainWindow::showAboutDialog()
{
    AboutDialog *ad = new AboutDialog(this);
    ad->show();
}

void MainWindow::newBibleWindow()
{
    BibleWindow *bw = new BibleWindow(settings, ui->actionPrint);
    connect(bw, SIGNAL(destroyed()), this, SLOT(subWindowClosed()));
    mdiArea->addSubWindow(bw, Qt::WindowTitleHint | Qt::CustomizeWindowHint | Qt::WindowCloseButtonHint
                          | Qt::WindowSystemMenuHint | Qt::WindowMaximizeButtonHint);
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
    autoTile = checked;
    if (autoTile == true)
        mdiArea->tileSubWindows();
}

void MainWindow::cascadeWindows()
{
    mdiArea->cascadeSubWindows();
}

void MainWindow::tileHorizontally()
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
        windows.at(i)->resize(mdiArea->width(), wHeight);
        windows.at(i)->move(0, y);
        y += wHeight;
    }
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
    int wWidth = mdiArea->width() / count;
    int x = 0;
    for (int i = 0; i < count; i++)
    {
        windows.at(i)->resize(wWidth, mdiArea->height());
        windows.at(i)->move(x, 0);
        x += wWidth;
    }
}

void MainWindow::print()
{
    QPrinter printer;
    qobject_cast<BibleWindow*>(mdiArea->activeSubWindow()->widget())->print(&printer);
}
