#include "Headers/updatedialog.h"
#include "ui_updatedialog.h"

updateDialog::updateDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::updateDialog) {
    ui->setupUi(this);
}

updateDialog::~updateDialog() {
    delete ui;
}

void updateDialog::on_accept_button_clicked() {
    system("reboot");
}

void updateDialog::on_reject_button_clicked() {
    close();
}

