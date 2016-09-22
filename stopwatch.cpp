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

    timer = new QTimer(this);
    timer->setInterval(950);
}

Stopwatch::~Stopwatch()
{
    delete ui;
}

void Stopwatch::on_pushButtonStart_clicked()
{
    paused ? startTimer() : stopTimer();
}

void Stopwatch::startTimer()
{
    paused = false;
    ui->pushButtonStart->setText("Stop");
    ui->lineEditNotes->setEnabled(false);
    start = QDateTime::currentDateTime();
    ui->labelTime->setText("00:00:00");
    timer->start();
}

void Stopwatch::stopTimer()
{

}
