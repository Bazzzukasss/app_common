/**
 * @file styled_widgets.h
 * @copyright (c) Copyright 2018 Zenuity AB
 * @author Zenuity VizTool Team <team-gl-viztool@zenuity.com>
 */

#pragma once

#include <QString>
#include <QLabel>
#include <QToolButton>
#include <QWidget>

#define DEFINE_STYLED_LABEL(type_name, label_color, bg_color, font_size, font_weight) \
    class type_name : public StyledLabel \
    { \
        Q_OBJECT \
     public: \
        type_name(QWidget* parent = nullptr) : \
            StyledLabel(app_style::color::label_color, app_style::color::bg_color, app_style::size::font_size, \
                        app_style::font::kFamily, app_style::font::kStyleNormal, app_style::font::font_weight, parent) \
        {} \
    };

#define DEFINE_STYLED_TOOLBUTTON(type_name, icon_name, text_color, bg_color, radius, text_size) \
    class type_name : public StyledToolButton \
    { \
        Q_OBJECT \
     public: \
        type_name(QWidget* parent = nullptr) : \
            StyledToolButton( \
                StyleData{app_style::color::text_color, app_style::color::bg_color, app_style::icon::icon_name, \
                          app_style::size::radius, app_style::size::text_size}, \
                parent) \
        {} \
    };

#define DEFINE_STYLED_ICON_TOOLBUTTON(type_name, icon_name) \
    DEFINE_STYLED_TOOLBUTTON(type_name, icon_name, kTransparent, kTransparent, kSize16, kSize16)

#define DEFINE_STYLED_FRAME(type_name, bg_color) \
    class type_name : public StyledFrame \
    { \
        Q_OBJECT \
     public: \
        type_name(QWidget* parent = nullptr) : StyledFrame(app_style::color::bg_color, parent) {} \
    };

namespace styles
{
const QString kLabel{"color : %1;"
                     "background-color: %2;"
                     "font-size: %3;"
                     "font-family: %4;"
                     "font-style: %5;"
                     "font-weight: %6;"};

const QString kToolButton{"QToolButton {"
                          "    color: %1;"
                          "    background-color: %2;"
                          "    border-image: url(:/images/icon-%3.svg);"
                          "    border-radius: %4;"
                          "    font-size: %5"
                          "}"};

const QString kToolButtonHover{"QToolButton:hover {"
                               "    color: %1;"
                               "    background-color: %2;"
                               "    border-image: url(:/images/icon-%3-hover.svg);"
                               "    border-radius: %4;"
                               "    font-size: %5"
                               "}"};

const QString kToolButtonPressed{"QToolButton:pressed,"
                                 "QToolButton:checked {"
                                 "    color: %1;"
                                 "    background-color: %2;"
                                 "    border-image: url(:/images/icon-%3-pressed.svg);"
                                 "    border-radius: %4;"
                                 "    font-size: %5"
                                 "}"};

const QString kFrame{"QFrame {"
                     "background-color: %1;"
                     "}"};

}  // namespace styles

class StyledFrame : public QFrame
{
    Q_OBJECT

 public:
    StyledFrame(const QString& bg_color, QWidget* parent = nullptr) : QFrame(parent)
    {
        setStyleSheet(styles::kFrame.arg(bg_color));
    }
};

class StyledLabel : public QLabel
{
    Q_OBJECT

 public:
    StyledLabel(const QString& color, const QString& bg_color, const QString& font_size, const QString& font_family,
                const QString& font_style, const QString& font_weight, QWidget* parent = nullptr) :
        QLabel(parent)
    {
        setStyleSheet(styles::kLabel.arg(color, bg_color, font_size, font_family, font_style, font_weight));
    }
};

class StyledToolButton : public QToolButton
{
    Q_OBJECT
 public:
    struct StyleData
    {
        const QString& color;
        const QString& bgColor;
        const QString& icon;
        const QString& border_radius;
        const QString& font_size;
    };

    StyledToolButton(const StyleData& style_normal, const StyleData& style_hover, const StyleData& style_pressed,
                     QWidget* parent = nullptr) :
        QToolButton(parent)
    {
        setStyleSheet(styles::kToolButton.arg(style_normal.color, style_normal.bgColor, style_normal.icon,
                                              style_normal.border_radius, style_normal.font_size) +
                      styles::kToolButtonHover.arg(style_hover.color, style_hover.bgColor, style_hover.icon,
                                                   style_hover.border_radius, style_hover.font_size) +
                      styles::kToolButtonPressed.arg(style_pressed.color, style_pressed.bgColor, style_pressed.icon,
                                                     style_pressed.border_radius, style_pressed.font_size));
    }

    StyledToolButton(const StyleData& style_data, QWidget* parent = nullptr) :
        StyledToolButton(style_data, style_data, style_data, parent)
    {}
};
