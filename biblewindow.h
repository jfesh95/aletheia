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
    explicit BibleWindow(struct Settings _settings, QAction *printAction, QWidget *parent = 0);
    ~BibleWindow();
    void print(QPrinter *_printer);
    void setTextFont(QFont);
    void setTextFontColor(QColor);
    void setTextBackgroundColor(QColor);

private slots:
    void goToVerse(const QString &, const QString &, const QString &);
    void bookChanged(const QString &, const QString & chapter = "1");
    void chapterChanged(int);
    void chapterChanged(QString);
    void linkClicked(QUrl);
    void showCrossReferences(bool);
    void copyText();
    
private:
    int setConfig(struct Settings _settings);
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
