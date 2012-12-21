#include "biblewindow.h"
#include "ui_biblewindow.h"

BibleWindow::BibleWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BibleWindow)
{
    ui->setupUi(this);

    setConfig();

    bibleManager = new BibleManager();

    bookSignalMapper = new QSignalMapper(this);

    bookMenu = new QMenu(this);
    QVector<std::string> booksList = QVector<std::string>::fromStdVector(bibleManager->getBookNames());
    for (int i = 0; i < booksList.size(); i++)
    {
        QAction *action = new QAction(QString::fromStdString(booksList[i]), this);
        bookMenu->addAction(action);
        connect(action, SIGNAL(triggered()), bookSignalMapper, SLOT(map()));
        bookSignalMapper->setMapping(action, QString::fromStdString(booksList[i]));
    }
    connect(bookSignalMapper, SIGNAL(mapped(const QString &)), this, SLOT(bookChanged(const QString &)));
    ui->bookSelector->setMenu(bookMenu);

    chapterSignalMapper = new QSignalMapper(this);
    chapterMenu = new QMenu(this);
    for (int i = 0; i < 10; i++)
    {
        QAction *action = new QAction(QString::number(i+1), this);
        chapterMenu->addAction(action);
        connect(action, SIGNAL(triggered()), chapterSignalMapper, SLOT(map()));
        chapterSignalMapper->setMapping(action, i+1);
    }
    connect(chapterSignalMapper, SIGNAL(mapped(const QString &)), this, SLOT(chapterChanged(const QString &)));
    ui->chapterSelector->setMenu(chapterMenu);

    bookChanged("Genesis");
}

BibleWindow::~BibleWindow()
{
    delete bibleManager;
    delete bookSignalMapper;
    delete chapterSignalMapper;
    delete bookMenu;
    delete chapterMenu;
    delete ui;
}

int BibleWindow::setConfig()
{
    ui->textView->setCurrentFont(QFont("serif", 12));
    return 0;
}

void BibleWindow::bookChanged(const QString & book)
{
    currentBook = book;
    ui->bookSelector->setText(book);
    chapterChanged("1");
}

void BibleWindow::chapterChanged(const QString & chapter)
{
    currentChapter = chapter;
    ui->chapterSelector->setText(currentChapter);
    ui->textView->setText(QString::fromStdString(bibleManager->getChapter(currentBook.toStdString(), currentChapter.toStdString())));
}
