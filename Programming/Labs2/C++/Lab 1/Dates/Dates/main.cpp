#include "Dates.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Dates window;
    window.setWindowTitle("Date");
    window.show();
    return a.exec();
}
