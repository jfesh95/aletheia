#include "biblewindow.h"
#include "ui_biblewindow.h"

#include "worksmanager.h"

BibleWindow::BibleWindow(Settings _settings, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BibleWindow)
{
    ui->setupUi(this);

    setConfig(_settings);

    bibleManager = new BibleManager();

    bookSignalMapper = new QSignalMapper(this);
    bookMenu = new QMenu(this);
    oldTestamentMenu = bookMenu->addMenu("Old Testament");
    newTestamentMenu = bookMenu->addMenu("New Testament");

    QVector<std::string> booksList = QVector<std::string>::fromStdVector(bibleManager->getBookNames());
    for (int i = 0; i < booksList.size(); i++)
    {
        QAction *action = new QAction(QString::fromStdString(booksList[i]), this);
        if (i < 39)
            oldTestamentMenu->addAction(action);
        else
            newTestamentMenu->addAction(action);
        connect(action, SIGNAL(triggered()), bookSignalMapper, SLOT(map()));
        bookSignalMapper->setMapping(action, QString::fromStdString(booksList[i]));
    }
    connect(bookSignalMapper, SIGNAL(mapped(const QString &)), this, SLOT(bookChanged(const QString &)));
    ui->bookSelector->setMenu(bookMenu);

    chapterSignalMapper = new QSignalMapper(this);
    chapterMenu = new QMenu(this);
    ui->chapterSelector->setMenu(chapterMenu);

    bookChanged("Genesis");
    connect(ui->textView, SIGNAL(anchorClicked(QUrl)), this, SLOT(linkClicked(QUrl)));
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

int BibleWindow::setConfig(Settings _settings)
{
    _showCrossReferences = false;
    ui->textView->setFont(_settings.font);
    return 0;
}

void BibleWindow::goToVerse(const QString & book, const QString & chapter, const QString & verse)
{
    if (currentBook != book)
        bookChanged(book, chapter);
    else if (currentChapter != chapter)
        chapterChanged(chapter);

    ui->textView->find(verse);

}

void BibleWindow::bookChanged(const QString & book, const QString & chapter)
{
    currentBook = book;
    ui->bookSelector->setText(book);

    chapterMenu->clear();
    QVector<std::string> chapterList = QVector<std::string>::fromStdVector(bibleManager->getNumberOfChapters(currentBook.toStdString()));
    for (int i = 0; i < chapterList.size(); i++)
    {
        QAction *action = new QAction(QString::fromStdString(chapterList[i]), this);
        chapterMenu->addAction(action);
        connect(action, SIGNAL(triggered()), chapterSignalMapper, SLOT(map()));
        chapterSignalMapper->setMapping(action, QString::fromStdString(chapterList[i]));
    }
    connect(chapterSignalMapper, SIGNAL(mapped(const QString &)), this, SLOT(chapterChanged(QString)));

    chapterChanged(chapter);
}

void BibleWindow::chapterChanged(int chapter)
{
    chapterChanged(QString::number(chapter));
}

void BibleWindow::chapterChanged(QString chapter)
{
    currentChapter = chapter;
    ui->chapterSelector->setText(currentChapter);

    QString text = QString::fromStdString(bibleManager->getChapter(currentBook.toStdString(), currentChapter.toStdString())).trimmed();
    QStringList list = text.split('\n');
    text.clear();

    for (int i = 0; i < list.length(); i++)
    {
        QString &verse = list[i];
        text += verse.replace('<', "&lt;").replace('>', "&gt;").replace('[', "<i>").replace(']', "</i>") + "<br />";

        if (_showCrossReferences)
        {
            int index = list[i].indexOf(" ");
            QStringList refs = QString::fromStdString(WorksManager::getCrossReference(currentBook.toStdString(), currentChapter.toStdString(), list[i].left(index).toStdString())).split('\t');
            for (int i = 0; i < refs.length(); i++)
            {
                text += "<a href=\"" + refs[i] + "\">" + refs[i] + "</a>";
                if (i+2 == refs.length())
                    text += "<br />";
                else text += " ";
            }

        }
    }
    ui->textView->setHtml(text); //.append("<a href=\"previous\">Previous Chapter</a> | <a href=\"next\">Next Chapter</a>"));
}

void BibleWindow::linkClicked(QUrl url)
{
    QString ref = url.toString();
    if (ref == "next")
    {
        // to do
    }
    else if (ref == "previous")
    {
        // to do
    }
    else
    {
        QStringList temp = ref.split(':');
        QStringList refParts;
        int index = temp[0].lastIndexOf(' ');
        refParts.append(temp[0].left(index));
        refParts.append(temp[0].right(index));
        refParts.append(temp[1]);
        goToVerse(temp[0].left(index), temp[0].mid(index), temp[1]);
    }
}

void BibleWindow::showCrossReferences(bool value)
{
    _showCrossReferences = value;
    chapterChanged(currentChapter);
}

void BibleWindow::setTextViewStyle()
{
    ui->textView->setFont(currentFont);
}

void BibleWindow::setTextFont(QFont font)
{
    currentFont = font;
    setTextViewStyle();
}

void BibleWindow::setTextFontColor(QColor color)
{
    fontColor = color;
    setTextViewStyle();
}

void BibleWindow::setTextBackgroundColor(QColor color)
{
    backgroundColor = color;
    setTextViewStyle();
}
