#include "edirrecord.h"
#include "ui_edirrecord.h"

EditRecord::EditRecord(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditRecord)
{
    ui->setupUi(this);
}

EditRecord::~EditRecord()
{
    delete ui;
}

QString EditRecord::firstname() const
{
    return ui->fnEdit->text();
}

QString EditRecord::middlename() const
{
    return ui->mdlEdit->text();
}

QString EditRecord::lastname() const
{
    return ui->lstEdit->text();
}
