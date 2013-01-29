#include "preferencesdialog.h"
#include "ui_preferencesdialog.h"
#include <QSize>

PreferencesDialog::PreferencesDialog(Settings _settings, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PreferencesDialog)
{
    ui->setupUi(this);

    settings = _settings;

    ui->fontFamilyComboBox->setCurrentFont(settings.font.family());
    ui->fontSizeSpinBox->setValue(settings.font.pointSize());

    fontColorButton = new ColorButton(settings.fontColor, this);
    backgroundColorButton = new ColorButton(settings.backgroundColor, this);
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
    settings.font.setFamily(family.family());
    updateSample();
}

void PreferencesDialog::changeFontSize(int size)
{
    settings.font.setPointSize(size);
    updateSample();
}

void PreferencesDialog::changeFontColor(QColor color)
{
    settings.fontColor = color;
    updateSample();
}

void PreferencesDialog::changeBackgroundColor(QColor color)
{
    settings.backgroundColor = color;
    updateSample();
}

void PreferencesDialog::updateSample()
{
    QString style = "QLabel {color: %1; background-color: %2;}";
    ui->sampleText->setStyleSheet(style.arg(settings.fontColor.name(), settings.backgroundColor.name()));
    ui->sampleText->setFont(settings.font);
}

void PreferencesDialog::on_buttonBox_accepted()
{
    dialogFinished(settings);
}
