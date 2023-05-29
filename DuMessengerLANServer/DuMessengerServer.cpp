#include "DuMessengerServer.h"
#include "DuMessengerSocket.h"
#include <QTextStream>
#include <QDebug>

namespace Messenger {
/**
 *  Constructs a DuMessengerServer object with the specified parent.
 *  parent The parent object.
 */

DuMessengerServer::DuMessengerServer(QObject *parent)
    : QTcpServer(parent)
{

}
/**
 *  Starts the server and listens for incoming connections on the specified port.
 *  port The port number to listen on.
 * return true if the server starts successfully, false otherwise.
 */

bool DuMessengerServer::startServer(quint16 port)
{
    return listen(QHostAddress::Any, port);
}

/**
 *  Handles an incoming connection from a client.
 * handle The socket descriptor of the connected client.
 */
void DuMessengerServer::incomingConnection(qintptr handle)
{
    qDebug() << "Client connected with handle: " << handle;
    auto socket = new DuMessengerSocket(handle, this);
    mSockets << socket;

    for (auto i : mSockets) {
        QTextStream T(i);
        T << "Server: Connected: " << handle;
        i->flush();
    }

    connect(socket, &DuMessengerSocket::DuReadyRead, [&](DuMessengerSocket *S) {
        qDebug() << "DuReadyRead";
        QTextStream T(S);
        auto text = T.readAll();

        for (auto i : mSockets) {
            QTextStream K(i);
            K << text;
            i->flush();
        }
    });

    connect(socket, &DuMessengerSocket::DuStateChanged, [&](DuMessengerSocket *S, int ST) {
        qDebug() << "DuStateChanged with handle" << S->socketDescriptor();
        if (ST == QTcpSocket::UnconnectedState) {
            qDebug() << "Unconncted state with handle: " << S->socketDescriptor();
            mSockets.removeOne(S);
            for (auto i : mSockets) {
                QTextStream K(i);
                K << "Server: Client " << S->socketDescriptor() << "Connected...";
                i->flush();
            }
        }
    });
}

} // namespace Messenger





