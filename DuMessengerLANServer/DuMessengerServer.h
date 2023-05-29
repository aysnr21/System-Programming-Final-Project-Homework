#ifndef DUMESSENGERSERVER_H
#define DUMESSENGERSERVER_H

#include <QTcpServer>

namespace Messenger {

class DuMessengerSocket;

/**
 *  The DuMessengerServer class represents a TCP server for the messenger application.
 *
 * This class is responsible for handling incoming client connections and managing the
 * communication sockets.
 */

class DuMessengerServer : public QTcpServer
{
public:
    /**
     *  Constructs a DuMessengerServer object.
     *  parent The parent object.
     */
    DuMessengerServer(QObject *parent = nullptr);
    /**
     * Starts the server and listens for incoming connections on the specified port.
     *  port The port number to listen on.
     * return `true` if the server starts successfully, `false` otherwise.
     */
    bool startServer(quint16 port);

protected:
    /**
     *  Reimplemented from QTcpServer.
     * This function is called by QTcpServer when a new connection is available.
     *  handle The socket descriptor of the incoming connection.
     */
    void incomingConnection(qintptr handle);

private:
    QList<DuMessengerSocket*> mSockets;/**< List of communication sockets connected to the server. */
};

} // namespace Messenger

#endif // DUMESSENGERSERVER_H
