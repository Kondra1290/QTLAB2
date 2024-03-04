#ifndef MYCLASS_H
#define MYCLASS_H

#include <QObject>
#include <QDate>

enum TYPE{DATE, NUMBER, STRING};
class MyClass : public QObject
{
    Q_OBJECT
public:
    explicit MyClass(QObject *parent = nullptr);
    void Process(QVariant, TYPE);

signals:
    void dataProcessed(QString);
private:
    QString procData;
};

#endif // MYCLASS_H
