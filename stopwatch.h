#ifndef STOPWATCH_H
#define STOPWATCH_H

#include <QMainWindow>

namespace Ui {
class Stopwatch;
}

class Stopwatch : public QMainWindow
{
    Q_OBJECT

public:
    explicit Stopwatch(QWidget *parent = 0);
    ~Stopwatch();

private:
    Ui::Stopwatch *ui;
};

#endif // STOPWATCH_H
