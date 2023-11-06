#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "svgparser.h"

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
    void on_btn_sourcePath_clicked();
    void on_btn_targetPath_clicked();
    void on_btn_exit_clicked();
    void on_btn_start_clicked();

    void setLogFile();

private:
    Ui::MainWindow *ui;

    QVector<SvgElement*> listOfElements;

    QVector<SvgElement*> parceFile(QString sourceFile);
    bool generateGcode(QString destFile);
};
#endif // MAINWINDOW_H
