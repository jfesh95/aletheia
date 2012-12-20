#include "biblewindow.h"
#include "ui_biblewindow.h"

BibleWindow::BibleWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BibleWindow)
{
    ui->setupUi(this);

    bibleManager = new BibleManager();

    signalMapper = new QSignalMapper(this);

    bookMenu = new QMenu(this);
    for (int i = 0; i < 10; i++)
    {
        QAction *action = new QAction(QString::number(i+1), this);
        bookMenu->addAction(action);
        connect(action, SIGNAL(triggered()), signalMapper, SLOT(map()));
        signalMapper->setMapping(action, QString::number(i+1));
    }
    connect(signalMapper, SIGNAL(mapped(const QString &)), this, SLOT(bookChanged(const QString &)));
    ui->bookSelector->setMenu(bookMenu);

    chapterMenu = new QMenu(this);
    for (int i = 0; i < 10; i++)
    {
        QAction *action = new QAction(QString::number(i+1), this);
        chapterMenu->addAction(action);
        connect(action, SIGNAL(triggered()), signalMapper, SLOT(map()));
        signalMapper->setMapping(action, i+1);
    }
    connect(signalMapper, SIGNAL(mapped(const int)), this, SLOT(chapterChanged(const int)));
    ui->chapterSelector->setMenu(chapterMenu);
}

BibleWindow::~BibleWindow()
{
    delete ui;
}

void BibleWindow::bookChanged(const QString & book)
{
    currentBook = book;
    ui->bookSelector->setText(book);
    chapterChanged(1);
}

void BibleWindow::chapterChanged(const int chapter)
{
    currentChapter = chapter;
    ui->chapterSelector->setText(QString::number(currentChapter));
    ui->textView->setText(QString::fromStdString(bibleManager->getChapter(currentBook.toStdString(), currentChapter)));
}
