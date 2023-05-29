#include <QCoreApplication> // Imports the Qt core application class
#include "DuMessengerServer.h" // Imports the DuMessengerServer class

using namespace Messenger;

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv); // Creates the Qt core application
    DuMessengerServer Server; // Creates an instance of the DuMessengerServer object
    if (!Server.startServer(54000)) { // Starts the DuMessengerServer on port 54000
        qDebug() << "Error:" << Server.errorString(); // Prints an error message if startup fails
        return 1; //Exits the program
    }
    qDebug() << "Server started ..."; // Prints "Server started ..." message
    return a.exec(); // Starts the Qt core application and runs the event loop
}
