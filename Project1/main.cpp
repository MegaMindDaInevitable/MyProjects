#include <QApplication>
#include "staffmember.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Staffmember staff;
    staff.show();
    return a.exec();
}
