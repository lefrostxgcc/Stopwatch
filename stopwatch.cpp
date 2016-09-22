#include "stopwatch.h"
#include "ui_stopwatch.h"

Stopwatch::Stopwatch(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Stopwatch)
{
    ui->setupUi(this);
}

Stopwatch::~Stopwatch()
{
    delete ui;
}
