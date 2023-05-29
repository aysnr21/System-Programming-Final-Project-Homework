#ifndef DUMESSENGERCONNECTIONDIALOG_H
#define DUMESSENGERCONNECTIONDIALOG_H

#include <QDialog>

namespace Ui {
class DuMessengerConnectionDialog;
}

namespace Messenger
{
class DuMessengerConnectionDialog : public QDialog
{
    Q_OBJECT
public:
    explicit DuMessengerConnectionDialog(QWidget *parent = nullptr);
    ~DuMessengerConnectionDialog();
    QString hostname() const; // Returns the entered hostname
    quint16 port() const; // Returns the entered port number
private slots:
    void on_ok_clicked(); // Slot for the OK button click
    void on_cancel_clicked(); // Slot for the Cancel button click
private:
    Ui::DuMessengerConnectionDialog *ui;
    QString mHostname; // Stores the entered hostname
    quint16 mPort; // Stores the entered port number
};

inline QString DuMessengerConnectionDialog::hostname() const
{
    return mHostname;
}

inline quint16 DuMessengerConnectionDialog::port() const
{
    return mPort;
}
}//end namespace Messenger
#endif // DUMESSENGERCONNECTIONDIALOG_H
