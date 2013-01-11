#ifndef BIBLEWINDOW_H
#define BIBLEWINDOW_H

#include "biblemanager.h"
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

namespace Ui {
class BibleWindow;
}

class BibleWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit BibleWindow(QWidget *parent = 0);
    ~BibleWindow();
    void setTextFont(QFont);
    void setTextFontColor(QColor);
    void setTextBackgroundColor(QColor);

private slots:
    void bookChanged(const QString &);
    void chapterChanged(int);
    void chapterChanged(QString);
    void linkClicked(QUrl);
    void showCrossReferences(bool);
    
private:
    int setConfig();
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
