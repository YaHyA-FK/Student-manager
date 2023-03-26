#include "studentindex.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    studentIndex w;
    w.show();

    return a.exec();
}
