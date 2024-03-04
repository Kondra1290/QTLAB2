#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDate>
#include "myclass.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void processText();
    void showProcessedData(QString);

private:
    Ui::MainWindow *ui;
    MyClass process;
    void Convert(QVariant&);
    TYPE type;
};
#endif // MAINWINDOW_H
