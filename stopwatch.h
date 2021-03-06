#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QMainWindow>
#include <QDateTime>
#include <QTimer>

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
    void timerTimeout();

protected:
    void closeEvent(QCloseEvent *event) override;

private:
    void startTimer();
    void stopTimer();
    void addNoteToGrid();
    void saveNoteToFile();

    Ui::Stopwatch *ui{};
    bool paused{true};
    QDateTime start{QDateTime::currentDateTime()};
    QTimer *timer{};
};

#endif // STOPWATCH_H
