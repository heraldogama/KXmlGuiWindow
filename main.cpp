#include <cstdlib>

#include <QApplication>
#include <QCommandLineParser>

#include <KAboutData>
#include <KLocalizedString>

#include "mainwindow.h"

int main (int argc, char *argv[])
{
    QApplication app(argc, argv);
    KLocalizedString::setApplicationDomain("tutorial2");
    
    KAboutData aboutData(
        QStringLiteral("tutorial2"),
        i18n("Tutorial 2"),
        QStringLiteral("1.0"),
        i18n("A simple text area using KAction etc."),
        KAboutLicense::GPL,
        i18n("(c) 2016"),
        i18n("Some text..."),
        QStringLiteral("http://example.com/"),
        QStringLiteral("submit@bugs.kde.org")
               );
    aboutData.addAuthor(i18n("Name"), i18n("Task"), QStringLiteral("you@email.com"), QStringLiteral("http://your.website.com"), QStringLiteral("OSC Username"));
    KAboutData::setApplicationData(aboutData);
    
    QCommandLineParser parser;
    parser.addHelpOption();
    parser.addVersionOption();
    aboutData.setupCommandLine(&parser);
    parser.process(app);
    aboutData.processCommandLine(&parser);
    
    MainWindow* window = new MainWindow();
    window->show();
    
    return app.exec();
}
