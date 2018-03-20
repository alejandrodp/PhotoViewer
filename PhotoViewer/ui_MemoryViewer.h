/********************************************************************************
** Form generated from reading UI file 'MemoryViewer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEMORYVIEWER_H
#define UI_MEMORYVIEWER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_MemoryViewer
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QTableWidget *table_pagesInMem;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *table_pagesInDisk;
    QGroupBox *groupBox_3;

    void setupUi(QDialog *MemoryViewer)
    {
        if (MemoryViewer->objectName().isEmpty())
            MemoryViewer->setObjectName(QStringLiteral("MemoryViewer"));
        MemoryViewer->resize(643, 464);
        verticalLayout = new QVBoxLayout(MemoryViewer);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        groupBox = new QGroupBox(MemoryViewer);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        table_pagesInMem = new QTableWidget(groupBox);
        if (table_pagesInMem->columnCount() < 2)
            table_pagesInMem->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        __qtablewidgetitem->setTextAlignment(Qt::AlignCenter);
        table_pagesInMem->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        __qtablewidgetitem1->setTextAlignment(Qt::AlignCenter);
        table_pagesInMem->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        table_pagesInMem->setObjectName(QStringLiteral("table_pagesInMem"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(table_pagesInMem->sizePolicy().hasHeightForWidth());
        table_pagesInMem->setSizePolicy(sizePolicy);
        table_pagesInMem->horizontalHeader()->setStretchLastSection(true);
        table_pagesInMem->verticalHeader()->setCascadingSectionResizes(false);
        table_pagesInMem->verticalHeader()->setProperty("showSortIndicator", QVariant(false));
        table_pagesInMem->verticalHeader()->setStretchLastSection(false);

        horizontalLayout->addWidget(table_pagesInMem);


        horizontalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(MemoryViewer);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        table_pagesInDisk = new QTableWidget(groupBox_2);
        if (table_pagesInDisk->columnCount() < 2)
            table_pagesInDisk->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        __qtablewidgetitem2->setTextAlignment(Qt::AlignCenter);
        table_pagesInDisk->setHorizontalHeaderItem(0, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        __qtablewidgetitem3->setTextAlignment(Qt::AlignCenter);
        table_pagesInDisk->setHorizontalHeaderItem(1, __qtablewidgetitem3);
        table_pagesInDisk->setObjectName(QStringLiteral("table_pagesInDisk"));
        sizePolicy.setHeightForWidth(table_pagesInDisk->sizePolicy().hasHeightForWidth());
        table_pagesInDisk->setSizePolicy(sizePolicy);
        table_pagesInDisk->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout_2->addWidget(table_pagesInDisk);


        horizontalLayout_3->addWidget(groupBox_2);


        verticalLayout->addLayout(horizontalLayout_3);

        groupBox_3 = new QGroupBox(MemoryViewer);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));

        verticalLayout->addWidget(groupBox_3);


        retranslateUi(MemoryViewer);

        QMetaObject::connectSlotsByName(MemoryViewer);
    } // setupUi

    void retranslateUi(QDialog *MemoryViewer)
    {
        MemoryViewer->setWindowTitle(QApplication::translate("MemoryViewer", "MemoryMonitor", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("MemoryViewer", "P\303\241ginas en memoria", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem = table_pagesInMem->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("MemoryViewer", "P\303\241gina", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem1 = table_pagesInMem->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("MemoryViewer", "Capacidad usada (%)", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MemoryViewer", "P\303\241ginas en disco", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem2 = table_pagesInDisk->horizontalHeaderItem(0);
        ___qtablewidgetitem2->setText(QApplication::translate("MemoryViewer", "P\303\241gina", Q_NULLPTR));
        QTableWidgetItem *___qtablewidgetitem3 = table_pagesInDisk->horizontalHeaderItem(1);
        ___qtablewidgetitem3->setText(QApplication::translate("MemoryViewer", "capacidad usada (%)", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MemoryViewer", "Informaci\303\263n general", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MemoryViewer: public Ui_MemoryViewer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEMORYVIEWER_H
