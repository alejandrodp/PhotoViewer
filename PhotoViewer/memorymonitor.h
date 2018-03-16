#ifndef MEMORYMONITOR_H
#define MEMORYMONITOR_H

#include <QDialog>

namespace Ui {
class MemoryMonitor;
}

class MemoryMonitor : public QDialog
{
    Q_OBJECT

public:
    explicit MemoryMonitor(QWidget *parent = 0);
    ~MemoryMonitor();

private:
    Ui::MemoryMonitor *ui;
};

#endif // MEMORYMONITOR_H
