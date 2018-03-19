#include "MemoryViewer.h"
#include "ui_MemoryViewer.h"
#include "MemoryManager/MemoryManager.h"

MemoryViewer::MemoryViewer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::MemoryViewer),
    manager(MemoryManager::getInstance())
{
    ui->setupUi(this);

}

void MemoryViewer::selector(MemoryManager::listNode pages){
    MemoryManager::listNode * pagesPointer = &pages;
    while(pagesPointer != nullptr){
        if(pages.inMemory){
            this->setPagesMemSlot(&pages);
        }else{
            this->setPagesDiskSlot(&pages);
        }
        pagesPointer = pagesPointer->next;
    }
}

void MemoryViewer::setPagesDiskSlot(MemoryManager::listNode * page) {
    QTableWidgetItem * pageRowDisk;
    QTableWidgetItem * usedRowDisk;
    int ROW = ui->table_pagesInMem->rowCount() + 1;

    pageRowDisk = new QTableWidgetItem("Página " + QString::number(page->page));
    pageRowDisk->setFlags(pageRowDisk->flags() ^ Qt::ItemIsEditable);

    pageRowDisk = new QTableWidgetItem(QString::number(100/page->used * page->used));
    pageRowDisk->setFlags(pageRowDisk->flags() ^ Qt::ItemIsEditable);

    ui->table_pagesInMem->setItem(ROW, PAGES, pageRowDisk);
    ui->table_pagesInMem->setItem(ROW, USAGE, usedRowDisk);
}

void MemoryViewer::setPagesMemSlot(MemoryManager::listNode * page) {
    QTableWidgetItem * pageRowMem;
    QTableWidgetItem * usedRowMem;
    int ROW = ui->table_pagesInMem->rowCount() + 1;

    pageRowMem = new QTableWidgetItem("Página " + QString::number(page->page));
    pageRowMem->setFlags(pageRowMem->flags() ^ Qt::ItemIsEditable);

    usedRowMem = new QTableWidgetItem(QString::number(100/page->used * page->used));
    usedRowMem->setFlags(usedRowMem->flags() ^ Qt::ItemIsEditable);

    ui->table_pagesInMem->setItem(ROW, PAGES, pageRowMem);
    ui->table_pagesInMem->setItem(ROW, USAGE, usedRowMem);
}



MemoryViewer::~MemoryViewer()
{
    delete ui;
}
