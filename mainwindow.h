#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <Qtsql/Qtsql>
#include <QtSql/QSqlQueryModel>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
void submitQuery();
void editRecord();

private:
    Ui::MainWindow *ui;

    QSqlQueryModel * sqlQueryModel;
    QSqlDatabase database;

    void checkErrors(const QSqlQuery& sqlQuery);
    void refreshTable();

};

#endif // MAINWINDOW_H
