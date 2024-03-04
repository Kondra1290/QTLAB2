#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->processButton, &QPushButton::clicked, this, &MainWindow::processText);
    connect(&process, &MyClass::dataProcessed, this, &MainWindow::showProcessedData);
}

void MainWindow::processText() {
    QString inputText = ui->inputLineEdit->text();

    QVariant variant(inputText);
    Convert(variant);
    QString processedText = inputText.toUpper();
    ui->resultLabel->setText(processedText);
    process.Process(variant, type);
}

void MainWindow::Convert(QVariant &value){
    //bool proc = false;
    type = TYPE::STRING;

    if(value.canConvert<QDate>() && value.toDate().isValid()){
        type = TYPE::DATE;
        ui->value->setText(value.toDate().toString("dd.MM.yyyy"));
        value.setValue(value.toDate());
    }
    else if(value.canConvert<double>() && value.toDouble()){
        double num = value.toDouble() * 2;
        type = TYPE::NUMBER;
        ui->value->setText(QString::number(num));
        value.setValue(value.toDouble());
    }
    else ui->value->setText(value.toString());

    ui->type->setText(value.typeName());
}

void MainWindow:: showProcessedData(QString data){
    ui->processedData->setText(data);
}

MainWindow::~MainWindow()
{
    delete ui;
}

