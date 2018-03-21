#include "launcher.h"
#include "ui_launcher.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QBuffer>
#include "MemoryViewer.h"

Launcher::Launcher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Launcher),
    photos(new SimpleList),
    menMan(MemoryManager::getInstance()),
    monitor(new MemoryViewer)

{
    ui->setupUi(this);
    connect(menMan, SIGNAL(change(MemoryManager::listNode)), monitor, SLOT(selector(MemoryManager::listNode)));
    monitor->show();
}

Launcher::~Launcher()
{
    delete ui;
}

void Launcher::on_action_ChangeDir_triggered()
{
    this->dir = QFileDialog::getExistingDirectory(this, tr("Seleccione una carpeta"),
                                                     QDir::currentPath(),
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);


        QDir directory(dir);
        QStringList images = directory.entryList(QStringList() << "*.jpeg" << "*.bmp"
                                                 << "*.BMP" << ".gif"
                                                 << ".GIF" << ".jpg"
                                                 << ".JPG" << "*.png"
                                                 << "*.PNG" << "*.JPEG",QDir::Files);
        foreach(QString filename, images) {
            QImage imgNew(dir + "/" + filename);

            std::cout << filename.toStdString() << " Size: " << imgNew.byteCount() << std::endl;

            std::bitset<32> pointer = menMan->allocate(imgNew.byteCount());
            QImage * toAllocate = static_cast<QImage *>(menMan->dereference(pointer));
            *toAllocate = imgNew;


            this->photos->AddEnd(pointer);
            ui->list_imgs->addItem(filename);

        }
}

void Launcher::on_action_Exit_triggered()
{
    monitor->close();
    this->close();
}

void Launcher::on_list_imgs_currentRowChanged(int currentRow)
{
    QImage * imgToGet = static_cast<QImage *>(menMan->dereference(photos->getValue(currentRow)));

    ui->label_imgPrev->setPixmap(QPixmap::fromImage(*imgToGet));
}
