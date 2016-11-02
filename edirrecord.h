#ifndef EDIRRECORD_H
#define EDIRRECORD_H

#include <QDialog>

namespace Ui {
    class EditRecord;
}

class EditRecord: public QDialog
{
    Q_OBJECT

public:
    explicit EditRecord(QWidget *parent = 0);
    QString firstname() const;
    QString middlename() const;
    QString lastname() const;
    ~EditRecord();

private:
    Ui::EditRecord *ui;
};

#endif // EDIRRECORD_H
