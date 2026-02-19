#include <QtWidgets>
#include "figure.h"
#include "mainwidget.h"
#include <iostream>
using namespace std;


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    figure_t figure;
    init_figure(figure);
    
    MainWidget w(figure);

    w.show();

    return a.exec();
}