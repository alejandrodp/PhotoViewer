#include "MemoryViewer.h"
#include "ui_MemoryViewer.h"
#include "MemoryManager/MemoryManager.h"
#include <iostream>

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
            this->setPagesMemSlot(pagesPointer);
        }else{
            this->setPagesDiskSlot(pagesPointer);
        }
        pagesPointer = pagesPointer->next;
    }
}

void MemoryViewer::setPagesDiskSlot(MemoryManager::listNode * page) {
    QTableWidgetItem * pageRowDisk;
    QTableWidgetItem * usedRowDisk;
    QTableWidget * table = ui->table_pagesInDisk;

    table->insertRow(table->rowCount());

    int ROW = table->rowCount() - 1;

    pageRowDisk = new QTableWidgetItem("Página " + QString::number(page->page));
    pageRowDisk->setFlags(pageRowDisk->flags() ^ Qt::ItemIsEditable);

    usedRowDisk = new QTableWidgetItem(QString::number(100/page->used * page->used));
    usedRowDisk->setFlags(pageRowDisk->flags() ^ Qt::ItemIsEditable);

    table->setItem(ROW, PAGES, pageRowDisk);
    table->setItem(ROW, USAGE, usedRowDisk);
}

void MemoryViewer::setPagesMemSlot(MemoryManager::listNode * page) {
    QTableWidgetItem * pageRowMem;
    QTableWidgetItem * usedRowMem;
    QTableWidget * table = ui->table_pagesInMem;

    table->insertRow(table->rowCount());

    int ROW = table->rowCount() -1;

    pageRowMem = new QTableWidgetItem("Página " + QString::number(page->page));
    pageRowMem->setFlags(pageRowMem->flags() ^ Qt::ItemIsEditable);

    usedRowMem = new QTableWidgetItem(QString::number((double)(100/page->used * page->used)));
    usedRowMem->setFlags(usedRowMem->flags() ^ Qt::ItemIsEditable);

    ui->table_pagesInMem->setItem(ROW, PAGES, pageRowMem);
    ui->table_pagesInMem->setItem(ROW, USAGE, usedRowMem);
}



MemoryViewer::~MemoryViewer()
{
    delete ui;
}
