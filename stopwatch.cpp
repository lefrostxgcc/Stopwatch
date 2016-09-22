#include "stopwatch.h"
#include "ui_stopwatch.h"
#include <QTableWidgetItem>
#include <QFile>
#include <QTextStream>

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

void Stopwatch::closeEvent(QCloseEvent * /*event*/)
{
    if (!paused)
        stopTimer();
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
    paused = true;
    timer->stop();
    addNoteToGrid();
    saveNoteToFile();
    ui->labelTime->setText("00:00:00");
    ui->lineEditNotes->setEnabled(true);
    ui->lineEditNotes->clear();
    ui->pushButtonStart->setText("Start");
    ui->lineEditNotes->setFocus();
}

void Stopwatch::addNoteToGrid()
{
    QTableWidgetItem *coStart = new QTableWidgetItem(start.toString("yyyy-MM-dd HH:mm"));
    QTableWidgetItem *coNotes = new QTableWidgetItem(ui->lineEditNotes->text());
    QTableWidgetItem *coTimer = new QTableWidgetItem(ui->labelTime->text());

    auto row = ui->grid->rowCount();
    ui->grid->setRowCount(row + 1);

    ui->grid->setItem(row, 1, coStart);
    ui->grid->setItem(row, 2, coNotes);
    ui->grid->setItem(row, 3, coTimer);
}

void Stopwatch::saveNoteToFile()
{
    QFile file{"notes.txt"};
    file.open(QIODevice::Append);

    QTextStream(&file)  << start.toString("yyyy-MM-dd HH:mm")   << '\t'
                        << ui->labelTime->text()                << '\t'
                        << ui->lineEditNotes->text()            << '\n';

    file.close();
}
