/********************************************************************************
** Form generated from reading UI file 'launcher.ui'
**
** Created by: Qt User Interface Compiler version 5.9.4
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LAUNCHER_H
#define UI_LAUNCHER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Launcher
{
public:
    QAction *action_ChangeDir;
    QAction *action_Exit;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_3;
    QListWidget *list_imgs;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_imgPrev;
    QMenuBar *menuBar;
    QMenu *menuOpciones;

    void setupUi(QMainWindow *Launcher)
    {
        if (Launcher->objectName().isEmpty())
            Launcher->setObjectName(QStringLiteral("Launcher"));
        Launcher->resize(847, 527);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(Launcher->sizePolicy().hasHeightForWidth());
        Launcher->setSizePolicy(sizePolicy);
        action_ChangeDir = new QAction(Launcher);
        action_ChangeDir->setObjectName(QStringLiteral("action_ChangeDir"));
        action_Exit = new QAction(Launcher);
        action_Exit->setObjectName(QStringLiteral("action_Exit"));
        centralWidget = new QWidget(Launcher);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout_3 = new QHBoxLayout(groupBox);
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        list_imgs = new QListWidget(groupBox);
        list_imgs->setObjectName(QStringLiteral("list_imgs"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(list_imgs->sizePolicy().hasHeightForWidth());
        list_imgs->setSizePolicy(sizePolicy1);

        horizontalLayout_3->addWidget(list_imgs);


        horizontalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_imgPrev = new QLabel(groupBox_2);
        label_imgPrev->setObjectName(QStringLiteral("label_imgPrev"));
        QSizePolicy sizePolicy2(QSizePolicy::Ignored, QSizePolicy::Ignored);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(label_imgPrev->sizePolicy().hasHeightForWidth());
        label_imgPrev->setSizePolicy(sizePolicy2);
        label_imgPrev->setPixmap(QPixmap(QString::fromUtf8("../../../../Google Drive/Fondos/1_aura.jpg")));
        label_imgPrev->setScaledContents(true);
        label_imgPrev->setAlignment(Qt::AlignCenter);

        horizontalLayout_2->addWidget(label_imgPrev);


        horizontalLayout->addWidget(groupBox_2);

        horizontalLayout->setStretch(0, 4);
        horizontalLayout->setStretch(1, 12);
        Launcher->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(Launcher);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 847, 22));
        menuOpciones = new QMenu(menuBar);
        menuOpciones->setObjectName(QStringLiteral("menuOpciones"));
        Launcher->setMenuBar(menuBar);

        menuBar->addAction(menuOpciones->menuAction());
        menuOpciones->addAction(action_ChangeDir);
        menuOpciones->addAction(action_Exit);

        retranslateUi(Launcher);

        QMetaObject::connectSlotsByName(Launcher);
    } // setupUi

    void retranslateUi(QMainWindow *Launcher)
    {
        Launcher->setWindowTitle(QApplication::translate("Launcher", "PhotoViewer", Q_NULLPTR));
        action_ChangeDir->setText(QApplication::translate("Launcher", "Cambiar carpeta", Q_NULLPTR));
        action_Exit->setText(QApplication::translate("Launcher", "Salir", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("Launcher", "Lista de im\303\241genes disponibles", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Launcher", "Im\303\241gen seleccionada", Q_NULLPTR));
        label_imgPrev->setText(QString());
        menuOpciones->setTitle(QApplication::translate("Launcher", "Opciones", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Launcher: public Ui_Launcher {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LAUNCHER_H
