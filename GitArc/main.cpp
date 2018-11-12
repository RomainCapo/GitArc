#include "gaviewmainmenu.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    GAViewMainMenu w;
    w.show();

    return a.exec();
}
