#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFile>
#include <QFileDialog>
#include <QMessageBox>
#include <QXmlStreamReader>

#include "gcodegenerator.h"


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
    if(ui->line_sourcePath->text().isEmpty()){
        QMessageBox::critical(this, "Не указан исходный файл", "Укажите корректный файл svg для разбора");
        return;
    }

    if(ui->line_targetPath->text().isEmpty()){
        QMessageBox::critical(this, "Не указан файл назначения", "Укажите файл для сохранения Gcode");
        return;
    }

    setLogFile();

    listOfElements = parceFile(ui->line_sourcePath->text());
    if(listOfElements.isEmpty()){
        QMessageBox::critical(this, "Ошибка", "При разборе, svg элементов не обнаружено, проверте исходный файл");
    }

    if(generateGcode(ui->line_targetPath->text())){            //NOTE Если хочется разделить поцессы, вынести в отдельную процедуру
        QMessageBox::information(this, "Завершено", "Генерирование Gcode успешно завершено");
    } else {
         QMessageBox::critical(this, "Ошибка", "При генерации gcode произощла ошибка, посмотрите файл лога");
    }
}

void MainWindow::setLogFile()
{
    if(ui->cb_logFile->isChecked())
        Logger::instance()->setLogFile(QString("log_%1.txt").arg(QDateTime::currentDateTime().toString("yyyy-MM-dd_hh-mm-ss")));
    else
        Logger::instance()->setLogFile(QString());

    Logger::instance()->setConsoleLog(ui->cb_logConsole->isChecked());
}

QVector<SvgElement *> MainWindow::parceFile(QString sourceFile)
{
    SvgParser *parcer = new SvgParser();
    return parcer->parsing(sourceFile);

}

bool MainWindow::generateGcode(QString destFile)
{
    GcodeGenerator *generator = new GcodeGenerator(destFile);
    return generator->genarate(listOfElements);
}

