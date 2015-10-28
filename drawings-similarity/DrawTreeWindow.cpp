#include "DrawTreeWindow.h"
#include "ui_DrawTreeWindow.h"

DrawTreeWindow::DrawTreeWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::DrawTreeWindow)
{
    ui->setupUi(this);
}

DrawTreeWindow::~DrawTreeWindow()
{
    delete ui;
}
