#include "multicolumnmenu.h"

MultiColumnMenu::MultiColumnMenu(QWidget *parent) :
    QWidget(parent)
{
    setWindowFlags(Qt::Popup);
}

QAction* MultiColumnMenu::addAction(QAction *action)
{
    QWidget::addAction(action);
    return action;
}
