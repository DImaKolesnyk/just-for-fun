#include "MainWindow.h"
#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPalette palWhite;
    palWhite.setColor(  ui->LeftWidget->backgroundRole(), Qt::white);
    ui->LeftWidget->setPalette( palWhite);
    ui->LeftWidget->setAutoFillBackground(true);
    ui->RightWidget->setPalette(palWhite);
    ui->RightWidget->setAutoFillBackground(true);

    controller = new Controller(ui->LeftWidget, ui->RightWidget);

//   QObject::connect( ui->LeftWidget, SIGNAL(DotCreated(QPoint)),
//                      controller, SLOT(controleLeftWidget(QPoint)));
    QObject::connect( ui->LeftWidget, SIGNAL(DotCreated(QPoint)),
                       controller, SLOT(addDotToLeftWidget(QPoint)));

    QObject::connect( ui->RightWidget, SIGNAL(DotCreated(QPoint)),
                      controller, SLOT(addDotToRightWidget(QPoint)));

    QObject::connect(ui->pushButton,  SIGNAL(clicked()),
                     controller, SLOT(buttonClicked()));
    QObject::connect(ui->pushButton_2, SIGNAL(clicked()),
                     controller, SLOT(clearDrawingPlace()));

    QObject::connect(ui->LeftWidget, SIGNAL(mouseMove(QPoint)),
                     controller, SLOT(lengthBetweenMouseAndContour(QPoint)));

    QObject::connect(controller, SIGNAL(changeLabel(QString)),
                     ui->label, SLOT(setText(QString)));

    QObject::connect(ui->doubleSpinBox, SIGNAL(valueChanged(double)),
                     controller, SLOT(epsChanged(double)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
