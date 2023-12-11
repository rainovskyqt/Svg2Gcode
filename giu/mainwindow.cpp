#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDateTime>
#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QXmlStreamReader>
#include <QRegularExpression>

#include "src/fccodemaker.h"


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
#include <QDebug>
void MainWindow::on_btn_exit_clicked()
{
    QRegExp del("[mclz]");
    // qDebug() << QString("m 439.28,734.64 c -0.90974,-0.22743 -25.359,8.0739 -25.359,8.0739 l 0.22744,1.8195 26.269,-8.5288 z",
    //                     QString::SplitBehavior).split(del);
    qApp->exit(0);
}

void MainWindow::on_btn_start_clicked()
{
    if(!checkFilesPaths())
        return;

    setLogFile();

    QString errorString;
    FCCodeMaker converter;

    QString gcode = converter.convert(ui->line_sourcePath->text(), errorString);

    if(!errorString.isEmpty()){
        Logger::instance()->write(errorString);
        QMessageBox::critical(this, "Ошибка записи конвертации", errorString);
        return;
    }

    QFile dest(ui->line_targetPath->text());
    if(!dest.open(QIODevice::WriteOnly|QIODevice::Text)){
        QMessageBox::critical(this, "Ошибка записи", QString("Не удается записать файл результата\n%1").arg(errorString));
        return;
    }

    dest.write(gcode.toLatin1());
    dest.close();
}

void MainWindow::setLogFile()
{
    if(ui->cb_logFile->isChecked())
        Logger::instance()->setLogFile(QString("log_%1.txt").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd_hh-mm-ss")));
    else
        Logger::instance()->setLogFile(QString());

    Logger::instance()->setConsoleLog(ui->cb_logConsole->isChecked());
}

bool MainWindow::checkFilesPaths()
{
    if(ui->line_sourcePath->text().isEmpty()){
        QMessageBox::critical(this, "Не указан исходный файл", "Укажите корректный файл svg для разбора");
        return false;
    }

    if(ui->line_targetPath->text().isEmpty()){
        QMessageBox::critical(this, "Не указан файл назначения", "Укажите файл для сохранения Gcode");
        return false;
    }

    return true;
}

