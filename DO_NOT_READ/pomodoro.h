#ifndef POMODORO_H
#define POMODORO_H

#include "IPomodoro.h"

#include <QWidget>
#include <atomic>
#include <memory>
#include <thread>

namespace Ui {
class Pomodoro;
}

class Pomodoro : public QWidget
{
    Q_OBJECT
    using CountdownT = std::unique_ptr<CppLondonUni::IThreadedCountdown>;
public:
    explicit Pomodoro(CountdownT&&, QWidget* parent = nullptr);
    ~Pomodoro();

private slots:
    void on_btnControl_clicked();

private:
    std::unique_ptr<CppLondonUni::IThreadedCountdown> countDown;
    std::unique_ptr<Ui::Pomodoro> ui;
};

#endif // POMODORO_H
