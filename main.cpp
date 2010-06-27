 #include <QApplication>

 #include "mainWindow.h"

 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     mainWindow widget;
     widget.show();
     return app.exec();
 }