#include "application.h"
#include <QFile>
#include <QTextStream>
#include <QFontDatabase>

Application::Application(int& argc, char** argv, int flags) : QApplication(argc, argv, flags)
{}

void Application::addStyles(const QStringList& files)
{
    QString styleSheet;
    for (const auto& file : files)
    {
        styleSheet += loadStyleSheet(file);
    }
    setStyleSheet(styleSheet);
}

void Application::addFonts(const QStringList& files)
{
    for (const auto& file : files)
    {
        QFontDatabase::addApplicationFont(file);
    }
}

QString Application::loadStyleSheet(const QString &file)
{
    QString styleSheet;
    QFile styleFile(file);

    if (styleFile.exists())
    {
        styleFile.open(QFile::ReadOnly | QFile::Text);
        QTextStream ts(&styleFile);

        styleSheet += ts.readAll();
    }

    return styleSheet;
}
