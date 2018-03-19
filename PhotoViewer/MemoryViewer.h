#ifndef MEMORYVIEWER_H
#define MEMORYVIEWER_H

#include <QDialog>
#include "MemoryManager/MemoryManager.h"

namespace Ui {
class MemoryViewer;
}



class MemoryViewer : public QDialog
{
    Q_OBJECT

public:
    explicit MemoryViewer(QWidget *parent = 0);
    ~MemoryViewer();
    void setPagesMemSlot(MemoryManager::listNode * page);
    void setPagesDiskSlot(MemoryManager::listNode * page);

private slots:
    void on_pushButton_clicked();

private:
    Ui::MemoryViewer *ui;
    MemoryManager * manager;

    enum Columns {
        PAGES, USAGE
    };
};

#endif // MEMORYVIEWER_H
