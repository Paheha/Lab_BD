#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "edirrecord.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->submitButton, SIGNAL(clicked()), this,SLOT(submitQuery()));
    connect(ui->pushButton, SIGNAL(clicked()), this,SLOT(editRecord()));

    sqlQueryModel = new QSqlQueryModel();
    ui ->sqlQueryTableView->setModel(sqlQueryModel);

    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("U:/DataBase/database/students.sqlite");
    bool open = database.open();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::submitQuery()
{
    sqlQueryModel->setQuery(QSqlQuery(ui->sqlQueryTextEdit->toPlainText()));
    checkErrors(sqlQueryModel->query());

}

void MainWindow::checkErrors(const QSqlQuery& sqlQuery)
{
    if(sqlQuery.lastError().type() != QSqlError::NoError)
    {
        ui->statusBar->showMessage(sqlQuery.lastError().text());
    };
}

void MainWindow::refreshTable()
{
    sqlQueryModel->setQuery("SELECT * FROM students");
    checkErrors(sqlQueryModel->query());
}
void MainWindow::editRecord()
{
    EditRecord* editRecord = new EditRecord;
    if (editRecord->exec() == QDialog::Accepted)
    {
        QString queryString = QString ("insert into  students(firstname,middlename,lastname)  values('%1', '%2', '%3')")
                                       .arg(editRecord->firstname()) .arg(editRecord->middlename()) .arg(editRecord->lastname());
        QSqlQuery query;
        query.exec(queryString);
        checkErrors(query);
        refreshTable();
    }

    delete editRecord;
}

