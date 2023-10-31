#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>


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


void MainWindow::on_btn_sourcePath_clicked()
{
    QString path = QFileDialog::getOpenFileName(this, "SVG файл");

    if(path.isEmpty())
        return;

    ui->line_sourcePath->setText(path);
}


void MainWindow::on_btn_targetPath_clicked()
{
    QString path = QFileDialog::getSaveFileName(this, "Файл для сохранения");

    if(path.isEmpty())
        return;

    ui->line_targetPath->setText(path);
}

void MainWindow::on_btn_exit_clicked()
{
    qApp->exit(0);
}


void MainWindow::on_btn_start_clicked()
{
    QFile svgFile(ui->line_sourcePath->text());
    if(!svgFile.open(QIODevice::ReadOnly)){
        QMessageBox::critical(this, "Ошибка файла", svgFile.errorString());\
        return;
    }
}
