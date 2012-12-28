#include "preferencesdialog.h"
#include "ui_preferencesdialog.h"
#include <QSize>

PreferencesDialog::PreferencesDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreferencesDialog)
{
    ui->setupUi(this);

    font.setFamily("serif");
    font.setPointSize(12);
    fontColor = Qt::black;
    backgroundColor = Qt::white;

    ui->fontFamilyComboBox->setFont(font.family());
    ui->fontSizeSpinBox->setValue(font.pointSize());

    fontColorButton = new ColorButton(fontColor, this);
    backgroundColorButton = new ColorButton(backgroundColor, this);
    ui->fontForm->addRow("Color:", fontColorButton);
    ui->bibleViewForm->addRow("Background color:", backgroundColorButton);

    connect(ui->fontFamilyComboBox, SIGNAL(currentFontChanged(QFont)), this, SLOT(changeFontFamily(QFont)));
    connect(ui->fontSizeSpinBox, SIGNAL(valueChanged(int)), this, SLOT(changeFontSize(int)));
    connect(fontColorButton, SIGNAL(colorChanged(QColor)), this, SLOT(changeFontColor(QColor)));
    connect(backgroundColorButton, SIGNAL(colorChanged(QColor)), this, SLOT(changeBackgroundColor(QColor)));

    updateSample();
}

PreferencesDialog::~PreferencesDialog()
{
    delete ui;
}

void PreferencesDialog::changeFontFamily(QFont family)
{
    font.setFamily(family.family());
    updateSample();
}

void PreferencesDialog::changeFontSize(int size)
{
    font.setPointSize(size);
    updateSample();
}

void PreferencesDialog::changeFontColor(QColor color)
{
    fontColor = color;
    updateSample();
}

void PreferencesDialog::changeBackgroundColor(QColor color)
{
    backgroundColor = color;
    updateSample();
}

void PreferencesDialog::updateSample()
{
    QString style = "QLabel {color: %1; background-color: %2;}";
    ui->sampleText->setStyleSheet(style.arg(fontColor.name(), backgroundColor.name()));
    ui->sampleText->setFont(font);
}

QFont PreferencesDialog::getFont()
{
    return font;
}

QColor PreferencesDialog::getFontColor()
{
    return fontColor;
}

QColor PreferencesDialog::getBackgroundColor()
{
    return backgroundColor;
}
