#ifndef BIBLEWINDOW_H
#define BIBLEWINDOW_H

#include "biblemanager.h"
#include "settings.h"
#include "QWidget"
#include "QMenu"
#include "QSignalMapper"
#include "QAction"
#include "QString"
#include <QStringList>
#include "QVector"
#include <QFont>
#include <QColor>
#include <QUrl>
#include <QPrinter>

namespace Ui {
class BibleWindow;
}

class BibleWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit BibleWindow(const struct Settings & _settings, QAction *printAction, QWidget *parent = 0);
    ~BibleWindow();
    void print(QPrinter *_printer);
    void setTextFont(QFont);
    void setTextFontColor(QColor);
    void setTextBackgroundColor(QColor);
    void setShowCrossReferences(bool);
    void changeBook(const QString &, const QString & chapter = "1");
    void changeChapter(int);
    void changeChapter(QString);
    void goToVerse(const QString &, const QString &, const QString &);

public slots:
    void showCrossReferences(bool);

private slots:
    void bookChanged(const QString &);
    void chapterChanged(const QString &);
    void linkClicked(QUrl);
    void copyText();
    
private:
    int setConfig(const struct Settings & _settings);
    void setTextViewStyle();

    Ui::BibleWindow *ui;
    BibleManager *bibleManager;
    QSignalMapper *bookSignalMapper;
    QSignalMapper *chapterSignalMapper;
    QMenu *bookMenu;
    QMenu *oldTestamentMenu;
    QMenu *newTestamentMenu;
    QMenu *chapterMenu;
    QString currentBook;
    QString currentChapter;
    bool _showCrossReferences;
    QFont currentFont;
    QColor fontColor;
    QColor backgroundColor;
};

#endif // BIBLEWINDOW_H
