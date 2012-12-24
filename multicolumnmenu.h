#ifndef MULITCOLUMNMENU_H
#define MULITCOLUMNMENU_H

#include <QWidget>
#include <QAction>

class MulitColumnMenu : public QWidget
{
    Q_OBJECT
public:
    explicit MulitColumnMenu(QWidget *parent = 0);
    QAction* addAction(QAction *action);
    
signals:
    
public slots:
    
};

#endif // MULITCOLUMNMENU_H
