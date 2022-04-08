#include "mainwindow.h"

MainWindow::MainWindow()
{
    setWindowTitle("Main Window");
    resize(400, 700);
    QLabel *mainLabel = new QLabel("Main Widget");
    setCntralWidget(mainLabel);
    mainLabel->setAlignment(Qt::AlignCenter);
}
