#pragma once

#include <QApplication>

class Application : public QApplication
{
    Q_OBJECT
 public:
    Application(int& argc, char** argv, int flags = ApplicationFlags);

    void addStyles(const QStringList& files);
    void addFonts(const QStringList& files);
    static QString loadStyleSheet(const QString& file);
};
