 #include <QApplication>
 
 #include "periodsystembase.h"
 
 int main(int argc, char *argv[])
 {
     QApplication app(argc, argv);
     periodSystem widget;
     widget.show();
     return app.exec();
 }