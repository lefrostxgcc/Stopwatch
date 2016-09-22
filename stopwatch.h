#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QMainWindow>
#include <QDateTime>

namespace Ui {
class Stopwatch;
}

class Stopwatch : public QMainWindow
{
    Q_OBJECT

public:
    explicit Stopwatch(QWidget *parent = 0);
    ~Stopwatch();

public slots:
    void on_pushButtonStart_clicked();

private:
    void startTimer();
    void stopTimer();

    Ui::Stopwatch *ui{};
    bool paused{true};
    QDateTime start{QDateTime::currentDateTime()};
};

#endif // STOPWATCH_H
