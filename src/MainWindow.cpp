#include "MainWindow.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow::QMainWindow(parent)
{
    mainBoard = new Board;
    setCentralWidget(mainBoard);
    setFixedSize(QSize(640, 640));
    setStyleSheet(QString("background-color: #744918"));
}