#ifndef SETTINGS_H
#define SETTINGS_H

#include <QFont>
#include <QColor>

struct Settings
{
    // Visual
    QFont font;
    QColor fontColor;
    QColor backgroundColor;

    // Display settings
    bool showCrossrefs;
};

#endif // SETTINGS_H
