#include "widget.h"
#include "ui_widget.h"
#include "dumessengerconnectiondialog.h"
#include <QTextStream>

namespace Messenger {

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this); // Set up the user interface for the widget
    mSocket = new QTcpSocket(this); // Create a new instance of QTcpSocket

    connect(mSocket, &QTcpSocket::readyRead, [this]() {// Connect the readyRead signal of the socket to a lambda function
        QTextStream T(mSocket); // Create a QTextStream to read from the socket
        auto text = T.readAll(); // Read all available data from the socket
        ui->textEdit->append(text); // Append the received text to the text edit widget
    });
}

Widget::~Widget()
{
    delete ui;// Free the memory used by the UI
}

void Widget::on_send_clicked()
{
    QTextStream T(mSocket); // Create a QTextStream to write to the socket
    T << ui->nickname->text() << " : " << ui->message->text(); // Write the nickname and message to the socket
    mSocket->flush(); // Flush the socket to send the data immediately
    ui->message->clear(); // Clear the message input field
}

void Widget::on_bind_clicked()
{
    DuMessengerConnectionDialog D(this); // Create an instance of the connection dialog
    if (D.exec() == QDialog::Rejected) { // Execute the connection dialog and check if it was rejected
        return; // If rejected, return without performing any further actions
    }
    mSocket->connectToHost(D.hostname(), D.port()); // Connect the socket to the specified host and port from the dialog
}

} // namespace Messenger

