#include <QString>
#include <QMap>
#include <QHash>
#include <QDebug>
#include <iostream>
#include <QRegExp>


void QStringFeatures() {
   QString name("Ashish Thapa");

   // std::cout << name << std::endl; error
   // to convert into std::string
   std::string standardName = name.toStdString();
   std::cout << standardName << std::endl;
   // QString formatting
   auto entry = QString("Best entryFragger: %1 ,Best Sentinel: %2, Best agent: %3").arg("Raze","Astra","Jett");

   qDebug() << entry;



}

void QRegExpFeatures() {

   qDebug() << "QRegex Features";
   // Basic QString Validator, checks whether the QString is in hh:mm:ss
   QRegExp rg(R"(^([0-1]?\d|2[0-3])(?::([0-5]?\d))?(?::([0-5]?\d))?$)");
   qDebug() << "22:23:33 " <<  rg.exactMatch("22:23:33");
   qDebug() << "42:23:33" << rg.exactMatch("42:23:33");
   qDebug() << "23" << rg.exactMatch("23");
}

void QMapFeatures() {
    QMap<QString, int> map;
    map["one"] = 1;
    map["three"] = 3;
    map["seven"] = 7;
}

int main()
{
    QStringFeatures();
    QRegExpFeatures();
    QMapFeatures();
    return 0;
}
