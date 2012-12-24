#include "helpbrowser.h"
#include "ui_helpbrowser.h"

HelpBrowser::HelpBrowser(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::HelpBrowser)
{
    ui->setupUi(this);
}

HelpBrowser::~HelpBrowser()
{
    delete ui;
}
