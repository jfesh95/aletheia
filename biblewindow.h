#ifndef BIBLEWINDOW_H
#define BIBLEWINDOW_H

#include "biblemanager.h"
#include "QWidget"
#include "QMenu"
#include "QSignalMapper"
#include "QAction"
#include "QString"
#include "QVector"
#include "QFont"
#include "mulitcolumnmenu.h"

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
    void chapterChanged(const QString &);
    
private:
    int setConfig();

    Ui::BibleWindow *ui;
    BibleManager *bibleManager;
    QSignalMapper *bookSignalMapper;
    QSignalMapper *chapterSignalMapper;
    MultiColumnMenu *bookMenu;
    MultiColumnMenu *chapterMenu;
    QString currentBook;
    QString currentChapter;
};

#endif // BIBLEWINDOW_H
