#include "mainwindow.h"

#include <QApplication>
#include <QtSql>
#include "password.h"
#include <iostream>
#include <QVector>

using namespace std;
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QSqlDatabase db_conn = QSqlDatabase::addDatabase("QMYSQL");
    db_conn.setHostName("database-awesome.cc195vywqlyq.ap-south-1.rds.amazonaws.com");
    db_conn.setDatabaseName("contact_db");
    db_conn.setUserName("admin");
    db_conn.setPassword(PASSWORD);
    db_conn.setPort(3306);


    QVector<Routine> routine;

    if (db_conn.open()) {
        std::cout << "database connection succesfull" << std::endl;
        QSqlQuery statement("SELECT * FROM Routine",db_conn);
        QSqlRecord record = statement.record();

        std::cout << record.count() <<std::endl;
        while(statement.next()) {
            auto instructor = statement.value(record.indexOf("instructor")).toString();
            auto time_period = statement.value(record.indexOf("time_period")).toString();
            auto w_week = statement.value(record.indexOf("w_week")).toString();
            auto course_code = statement.value(record.indexOf("course_code")).toString();

            routine.append(Routine(instructor,time_period, w_week, course_code));
        }

    }else {
        std::cout << "couldn't connect" << std::endl;
    }

    MainWindow w(db_conn,routine);
    w.show();
    return a.exec();
}
