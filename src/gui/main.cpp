#include "widget.h"

#include <QApplication>
#include <QProcess>
#include <QStyleFactory>



sig_atomic_t exitFlag = 0;

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    Widget w;

    w.show();
    return app.exec();
}
