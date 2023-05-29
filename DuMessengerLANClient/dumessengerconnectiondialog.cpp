#include "dumessengerconnectiondialog.h"
#include "ui_dumessengerconnectiondialog.h"

namespace  Messenger
{
/**
 *  Constructor for DuMessengerConnectionDialog class.
 *
 *  parent The parent QWidget.
 */
DuMessengerConnectionDialog::DuMessengerConnectionDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DuMessengerConnectionDialog)
{
    ui->setupUi(this);
}
/**
 *  Destructor for DuMessengerConnectionDialog class.
 */

DuMessengerConnectionDialog::~DuMessengerConnectionDialog()
{
    delete ui;
}

/**
 *  Slot for the "OK" button click event.
 *
 * Gets the hostname and port values from the UI elements,
 * assigns them to the member variables, and accepts the dialog.
 */
void DuMessengerConnectionDialog::on_ok_clicked()
{
    mHostname = ui ->hostname ->text();
    mPort = ui->port->value();
    accept();
}

/**
 *  Slot for the "Cancel" button click event.
 *
 * Rejects the dialog.
 */

void DuMessengerConnectionDialog::on_cancel_clicked()
{
    reject();
}

} // end namespace Messenger





