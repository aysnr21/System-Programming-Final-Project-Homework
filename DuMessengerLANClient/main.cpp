#include "widget.h"
#include <QApplication>

using namespace Messenger;

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // Create a QApplication object to manage the application
    a.setStyle("fusion"); // Set the application style to Fusion
    Widget w; // Create an instance of the Widget class
    w.show(); //Show widget
    return a.exec(); // Execute the application event loop and return the exit code
}







