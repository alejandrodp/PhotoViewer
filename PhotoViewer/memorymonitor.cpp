#include "memorymonitor.h"
#include "ui_memorymonitor.h"

MemoryMonitor::MemoryMonitor(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MemoryMonitor)
{
    ui->setupUi(this);
}

MemoryMonitor::~MemoryMonitor()
{
    delete ui;
}
