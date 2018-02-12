#include "pomodoro.h"
#include "ui_pomodoro.h"

#include <chrono>
#include <cmath>
#include <iomanip>
#include <sstream>
#include <string>

using namespace CppLondonUni;
using namespace std::chrono;
using namespace std::chrono_literals;

static high_resolution_clock clk;

Pomodoro::Pomodoro(CountdownT&& countDown, QWidget* parent) :
    QWidget{parent},
    countDown{std::move(countDown)},
    ui{std::make_unique<Ui::Pomodoro>()}
{
    ui->setupUi(this);
}

Pomodoro::~Pomodoro()
{
}

void Pomodoro::on_btnControl_clicked()
{
    countDown->InvokeProcessLoop(ui->timeout->text().toUInt(),
        [&] (auto) {
            ui->curTime->setText(countDown->FormatCurrentTime().c_str());
            return false;
        });
}
