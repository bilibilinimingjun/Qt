#include "student.h"
#include <QDebug>

Student::Student(QObject *parent) : QObject(parent)
{

}

void Student::comeBackToClass()
{
    qDebug() << "laoding..." << endl;
}
