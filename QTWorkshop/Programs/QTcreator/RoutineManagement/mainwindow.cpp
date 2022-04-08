#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <QVectorIterator>
#include <QSql>
#include <QSqlQuery>



MainWindow::MainWindow(QSqlDatabase db_conn, QVector<Routine> r,QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , routine(r)
    , db_conn(db_conn)
{
    ui->setupUi(this);
    ui->routineTable->setRowCount(routine.count());

    int rowCounter = 0;
    QVectorIterator<Routine> i(routine);
    while(i.hasNext()) {
        Routine r = i.next();
        auto *week = new QTableWidgetItem(r.w_week);
        auto *instructor = new QTableWidgetItem(r.instructor);
        auto *timePeriod = new QTableWidgetItem(r.time_period);
        auto *courseCode = new QTableWidgetItem(r.course_code);

    ui->routineTable->setItem(rowCounter,0,week);
    ui->routineTable->setItem(rowCounter,1,courseCode);
    ui->routineTable->setItem(rowCounter,2,instructor);
    ui->routineTable->setItem(rowCounter,3,timePeriod);
    rowCounter++;
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
// courseCode
// instructor
// timePeriod
// week
//    std::cout << ui->courseCode->text().toStdString() << std::endl;
//    std::cout << ui->instructor->text().toStdString() << std::endl;
//    std::cout << ui->timePeriod->text().toStdString() << std::endl;
//    std::cout << ui->week->text().toStdString() << std::endl;

    int row = ui->routineTable->rowCount();
    ui->routineTable->setRowCount(row+1);

    auto *week = new QTableWidgetItem(ui->week->text());
    auto *instructor = new QTableWidgetItem(ui->instructor->text());
    auto *timePeriod = new QTableWidgetItem(ui->timePeriod->text());
    auto *courseCode = new QTableWidgetItem(ui->courseCode->text());


    ui->routineTable->setItem(row,0,week);
    ui->routineTable->setItem(row,1,courseCode);
    ui->routineTable->setItem(row,2,instructor);
    ui->routineTable->setItem(row,3,timePeriod);

    if(db_conn.isOpen()) {
        QSqlQuery ins_statement(db_conn);
        ins_statement.prepare("INSERT INTO Routine (instructor,course_code, time_period, w_week)" "VALUES(?, ?, ?, ?)");
        ins_statement.addBindValue(ui->instructor->text());
        ins_statement.addBindValue(ui->courseCode->text());
        ins_statement.addBindValue(ui->timePeriod->text());
        ins_statement.addBindValue(ui->week->text());
        ins_statement.exec();
        std::cout << "writing to database successful" << std::endl;

    }

}

