#ifndef DUMESSENGERSOCKET_H
#define DUMESSENGERSOCKET_H

#include <QTcpSocket>

namespace Messenger {
/**
 *  The DuMessengerSocket class represents a TCP socket for communication with clients.
 *
 * This class is a subclass of QTcpSocket and provides additional signals for handling
 * incoming data and socket state changes.
 */

class DuMessengerSocket : public QTcpSocket
{
    Q_OBJECT

public:
    /**
     *  Constructs a DuMessengerSocket object with the specified socket handle.
     *  handle The socket descriptor of the connected client.
     *  parent The parent object.
     */
    DuMessengerSocket(qintptr handle, QObject *parent = nullptr);

signals:
    /**
     *  Signal emitted when there is data available to be read from the socket.
     *  socket Pointer to the DuMessengerSocket emitting the signal.
     */
    void DuReadyRead(DuMessengerSocket*);
    /**
     * Signal emitted when the state of the socket changes.
     *  socket Pointer to the DuMessengerSocket emitting the signal.
     *  state The new state of the socket.
     */
    void DuStateChanged(DuMessengerSocket*, int);
};

} // namespace Messenger

#endif // DUMESSENGERSOCKET_H

