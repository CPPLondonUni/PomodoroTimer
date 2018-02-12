#include "pomodoro.h"
#include "ThreadedPomodoro.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QStyle>

using namespace CppLondonUni;

int main(int argc, char *argv[])
{
    QApplication a{argc, argv};
    Pomodoro w{std::make_unique<ThreadedPomodoro>()};
    w.setGeometry(QStyle::alignedRect(Qt::LeftToRight,
        Qt::AlignCenter, w.size(), a.desktop()->availableGeometry()));
    w.show();

    return a.exec();
}
