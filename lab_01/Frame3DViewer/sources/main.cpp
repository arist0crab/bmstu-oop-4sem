#include <QtWidgets>
#include "figure.h"
#include "mainwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    figure_t figure;
    figure_reset(figure);
    MainWidget w(figure);

    w.show();

    return a.exec();
}