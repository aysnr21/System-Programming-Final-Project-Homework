#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QTcpSocket>

namespace Ui {
class Widget;
}

namespace Messenger {
class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_send_clicked(); // Slot for the send button click
    void on_bind_clicked(); // Slot for the send bind click

private:
    Ui::Widget *ui;
    QTcpSocket *mSocket; // TCP socket for communication
};

} // namespace Messenger

#endif // WIDGET_H

