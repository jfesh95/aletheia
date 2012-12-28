#ifndef BIBLEWINDOW_H
#define BIBLEWINDOW_H

#include "biblemanager.h"
#include "QWidget"
#include "QMenu"
#include "QSignalMapper"
#include "QAction"
#include "QString"
#include "QVector"
#include <QFont>
#include <QColor>

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
    void chapterChanged(const QString &);
    
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
    QFont currentFont;
    QColor fontColor;
    QColor backgroundColor;
};

#endif // BIBLEWINDOW_H
