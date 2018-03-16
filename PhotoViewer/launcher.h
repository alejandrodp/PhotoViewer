#ifndef LAUNCHER_H
#define LAUNCHER_H

#include <QMainWindow>
#include <QListWidgetItem>
#include "structures/Lists/SimpleList.h"
#include "MemoryManager/MemoryManager.h"

namespace Ui {
class Launcher;
}

class Launcher : public QMainWindow
{
    Q_OBJECT

public:
    explicit Launcher(QWidget *parent = 0);
    ~Launcher();

private slots:
    void on_action_ChangeDir_triggered();

    void on_action_Exit_triggered();

    void on_list_imgs_currentRowChanged(int currentRow);

private:
    Ui::Launcher *ui;
    QString dir;
    SimpleList* photos;
    MemoryManager* menMan;
    QByteArray * getImageToBytes(QString file);

};

#endif // LAUNCHER_H
