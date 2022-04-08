#include <QApplication>
#include <QPushButton>
#include <QWidget>
#include <QGridLayout>
#include <QLineEdit>
#include <QDateTimeEdit>
#include <QSpinBox>
#include <QPushButton>
#include <QComboBox>
#include <QLabel>
#include <QFormLayout>
#include <QDial>
#include <QMainWindow>
#include <iostream>

#include "mainwindow.h"

#include <QDesktopServices>
#include <QString>
#include <QUrl>



void FormLayout() {
    QWidget *window = new QWidget;

    QFormLayout *layout = new QFormLayout;
    QLineEdit *firstNameLineEdit= new QLineEdit;
    QLineEdit *lastNameLineEdit= new QLineEdit;
    layout->addRow("First Name", firstNameLineEdit);
    layout->addRow("Last Name", lastNameLineEdit);
    window->setLayout(layout);
    window->show();

}

void HorizontalLayout() {
    QWidget *window = new QWidget;

    QPushButton *findButton = new QPushButton("Find");
    QLineEdit *findLineEdit= new QLineEdit;
    findLineEdit->setPlaceholderText("Enter your search Term");
    findLineEdit->setFixedWidth(400);
    QHBoxLayout *layout = new QHBoxLayout;
    layout->addWidget(findLineEdit);
    layout->addWidget(findButton);
    window->setLayout(layout);
    window->show();
}
void VerticalLayout() {
    QWidget *window = new QWidget;

    QPushButton *findButton = new QPushButton("Find");
    QLineEdit *findLineEdit= new QLineEdit;
    findLineEdit->setPlaceholderText("Enter your search Term");
    findLineEdit->setFixedWidth(400);
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(findLineEdit);
    layout->addWidget(findButton);
    window->setLayout(layout);
    window->show();
}


void GridLayout(QApplication &app) {
    QWidget *window = new QWidget;
    QGridLayout *layout = new QGridLayout;
    QLabel *nameLabel = new QLabel("Basic QT Application");
    QSpinBox *spinbox = new QSpinBox;
    QPushButton *verticalLayoutButton = new QPushButton("Show Vertical Layout") ;
    QPushButton *horizontalLayoutButton = new QPushButton("Show Horizontal layout") ;
    QPushButton *formLayoutButton = new QPushButton("Show Form layout") ;
    horizontalLayoutButton->setStyleSheet("QPushButton {background: red; color: white;}");

    QLineEdit *lineEdit = new QLineEdit;
    lineEdit->setStyleSheet("QLineEdit:hover {background-color: lightblue;}");
    spinbox->setRange(1,100);

    layout->addWidget(nameLabel,0,0);
    layout->addWidget(spinbox,1,0);
    layout->addWidget(lineEdit,1,1,1,2);
    layout->addWidget(verticalLayoutButton, 2,0,1,1);
    layout->addWidget(horizontalLayoutButton, 2,2,1,1);
    layout->addWidget(formLayoutButton, 3,0,1,3);


    QObject::connect(lineEdit, &QLineEdit::returnPressed, &app, [=](){
        QDesktopServices::openUrl(QUrl(QString("https://www.google.com/search?q=%1").arg(lineEdit->text())));
    });
    QObject::connect(verticalLayoutButton, &QPushButton::clicked, &app, [=]() {
        VerticalLayout();
    });

    QObject::connect(horizontalLayoutButton, &QPushButton::clicked, &app, [=]() {
        HorizontalLayout();
    });

    QObject::connect(formLayoutButton, &QPushButton::clicked, &app, [=]() {
        FormLayout();
    });

    window->setLayout(layout);
    window->show();
}

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);
    GridLayout(app);
    return app.exec();
}
