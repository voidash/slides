#pragma once
#include <QString>

struct Routine {
    public:
    Routine(QString ins, QString time, QString week, QString course_code )
        : instructor(ins), time_period(time), w_week(week), course_code(course_code) {}

        QString instructor;
        QString time_period;
        QString w_week;
        QString course_code;
};
