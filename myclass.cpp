#include "myclass.h"

MyClass::MyClass(QObject *parent)
    : QObject{parent}
{
}

void MyClass::Process(QVariant value, TYPE type){
    switch(type)
    {
        case DATE:
        {
            procData = value.toDate().toString("dddd d.MMMM.yyyy");
            break;
        }
        case NUMBER:
        {
            double num = value.toDouble();
            num *= -1;
            procData = QString::number(num);
            break;
        }
        case STRING:
        {
            QString data = value.toString().toLower();
            for(int i = 0; i < data.length(); i++){
                if(i%2 == 0) procData.append(data.at(i).toUpper());
                else procData.append(data.at(i));
            }

            QString data1 = value.toString().toLower();
            for(int i = 0; i < data.length(); i++){
                if(i%2 == 0) procData.append(data.at(i).toUpper());
                else procData.append(data.at(i));
            }

            QString data2 = value.toString().toLower();
            for(int i = 0; i < data.length(); i++){
                if(i%2 == 0) procData.append(data.at(i).toUpper());
                else procData.append(data.at(i));
            }
            break;
        }
        default:
            break;
    }

    emit dataProcessed(procData);
}
