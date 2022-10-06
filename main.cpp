#include "rest.h"
#include <QApplication>
#include <QFile>
int main(int argc, char *argv[])
{
    QFile file("./assets/style/index.css");

    QApplication a(argc, argv);
    rest w;
    if (file.open(QFile::ReadOnly)) {
        QString qss = QLatin1String(file.readAll());
        qApp->setStyleSheet(qss);
        file.close();
    }
    w.show();
    return a.exec();
}
