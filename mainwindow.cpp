#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "QMessageBox"
#include "QFileDialog"
#include "string"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_spinBox_valueChanged(int arg1)
{
    ui->tableWidget->setRowCount(arg1);
}


void MainWindow::on_pushButton_saveTxt_clicked() // сохранить в текстовом формате
{
    QString fileName;
    fileName = QFileDialog::getSaveFileName(this, \
    tr("Открыть файл"), "D:\\Work\\Study\\Programming\\Qt_worked\\2_sem\\1_practice\\Doci", tr("Text files(*.txt)"));
    if (fileName.isEmpty()){
        QMessageBox::question(this, "Ошибка", "Файл не выбран" );
    }
    else{
        QFile file;
        QString str;
        file.setFileName(fileName);
        file.open(QIODevice::WriteOnly);

        int size = ui->spinBox->value();
        str.setNum(size);
        str.append("\n");
        file.write(str.toUtf8());

        for(int i=0; i<size; i++){

            if (ui->tableWidget->item(i,0)==nullptr)
            {
                QTableWidgetItem * ti;
                ti = new QTableWidgetItem;
                ui->tableWidget->setItem(i,0,ti);



            }
            str = ui->tableWidget->item(i, 0) -> text();
            str.append("\n");
            file.write((str.toUtf8()));

        }
            file.close();
    }
}

void MainWindow::on_pushButton_openTxt_clicked() // изменение текстового
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, \
    tr("Открыть файл"), "D:\\Work\\Study\\Programming\\Qt_worked\\2_sem\\1_practice\\Doci", tr("Text files(*.txt)"));
    if (fileName.isEmpty()){
        QMessageBox::question(this, "Ошибка", "Файл не выбран" );
    }
    else{
        QFile file;
        file.setFileName(fileName);
        file.open(QIODevice::ReadOnly);

        QString str;
        QByteArray ba;
        int size;
        bool flag;
        ba = file.readLine();
        str.clear();
        str.append(ba);
        str.append("\n");

        size = str.toInt(&flag);

        if(!flag){
            QMessageBox::question(this, "Ошибка", "Не верный формат" );
        }
        else{
            for(int i=0; i<size; i++){

                if (ui->tableWidget->item(i,0)==nullptr)
                {
                    QTableWidgetItem * ti;
                    ti = new QTableWidgetItem;
                    ui->tableWidget->setItem(i,0,ti);

                }

                ba=file.readLine();
                str.clear();
                str.append(ba);
                str.remove("\n");
                ui->tableWidget->item(i, 0) -> setText(str);
            }
        }


            file.close();
    }
}


void MainWindow::on_pushButton_saveTxt_2_clicked() //сохранить в бинарном формате
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, \
    tr("Открыть файл"), "D:\\Work\\Study\\Programming\\Qt_worked\\2_sem\\1_practice\\Doci", tr("Text files(*.txt)"));
    if (fileName.isEmpty()){
        QMessageBox::question(this, "Ошибка", "Файл не выбран" );
    }
    else{
        QFile file;
        file.setFileName(fileName);
        file.open(QIODevice::ReadOnly);

        char * mas;
        int size_int = sizeof(int); // на случай разных размеров
        mas = new char[size_int]; // массив для образа памяти числа

        int size = ui->spinBox->value();
        memcpy(mas, &size, size_int);
        file.write((mas, size_int));


        for(int i=0; i<size; i++){

            if (ui->tableWidget->item(i,0)==nullptr)
            {
                QTableWidgetItem * ti;
                ti = new QTableWidgetItem;
                ui->tableWidget->setItem(i,0,ti);

            }

        }
            file.close();
            delete[] mas;
    }
}





void MainWindow::on_pushButton_openTxt_2_clicked() // очистить
{
    QString fileName;
    fileName = QFileDialog::getOpenFileName(this, \
    tr("Открыть файл"), "D:\\Work\\Study\\Programming\\Qt_worked\\2_sem\\1_practice\\Doci", tr("Text files(*.txt)"));
    if (fileName.isEmpty()){
        QMessageBox::question(this, "Ошибка", "Файл не выбран" );
    }
    else{
        QFile file;
        file.setFileName(fileName);
        file.open(QIODevice::ReadOnly);

        char * mas;
        int size_int = sizeof(int); // на случай разных размеров
        mas = new char[size_int];
        int size;

        file.read(mas, size_int);
        memcpy(mas, &size, size_int);

        // проверка на размеры
        if(file.size() ! );

        for(int i=0; i<size; i++){

            if (ui->tableWidget->item(i,0)==nullptr)
            {
                QTableWidgetItem * ti;
                ti = new QTableWidgetItem;
                ui->tableWidget->setItem(i,0,ti);

            }

        }
            file.close();
            delete[] mas;
    }
}


// 11 - 9 + текст.сохр
//12-11 + бин.сохр
// что записалось то и считалось, искажения с размером, защита от подмены
//можно шифровать с паролем
// в текстовом формате не обязательно разделять
//












