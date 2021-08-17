/*
fct-chess

Criado por:
Daniel Henrique Serezane Pereira
Gustavo Becelli Do Nacimento
*/

#include "mainwindow.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
