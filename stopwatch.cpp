#include "stopwatch.h"
#include "ui_stopwatch.h"

Stopwatch::Stopwatch(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Stopwatch)
{
    ui->setupUi(this);

    ui->grid->setColumnWidth(0, 25);
    ui->grid->setColumnWidth(1, 100);
    ui->grid->horizontalHeader()->setSectionResizeMode(2, QHeaderView::Stretch);
    ui->grid->setColumnWidth(3, 100);
}

Stopwatch::~Stopwatch()
{
    delete ui;
}
