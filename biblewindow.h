#ifndef BIBLEWINDOW_H
#define BIBLEWINDOW_H

#include "biblemanager.h"
#include <QWidget>
#include <QMenu>
#include <QSignalMapper>
#include <QAction>
#include <QString>

namespace Ui {
class BibleWindow;
}

class BibleWindow : public QWidget
{
    Q_OBJECT
    
public:
    explicit BibleWindow(QWidget *parent = 0);
    ~BibleWindow();

private slots:
    void bookChanged(const QString &);
    void chapterChanged(const int);
    
private:
    Ui::BibleWindow *ui;
    BibleManager *bibleManager;
    QSignalMapper *signalMapper;
    QMenu *bookMenu;
    QMenu *chapterMenu;
    QString currentBook;
    int currentChapter;
};

#endif // BIBLEWINDOW_H
