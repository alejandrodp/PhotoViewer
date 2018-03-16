#include "launcher.h"
#include "ui_launcher.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QBuffer>

Launcher::Launcher(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Launcher),
    photos(new SimpleList),
    menMan(MemoryManager::getInstance())
{
    ui->setupUi(this);

}

Launcher::~Launcher()
{
    delete ui;
}

void Launcher::on_action_ChangeDir_triggered()
{
    this->dir = QFileDialog::getExistingDirectory(this, tr("Open Directory"),
                                                     "/home",
                                                     QFileDialog::ShowDirsOnly
                                                     | QFileDialog::DontResolveSymlinks);


        QDir directory(dir);
        QStringList images = directory.entryList(QStringList() << "*.jpeg" << "*.JPEG",QDir::Files);
        foreach(QString filename, images) {
            QByteArray imgToBase64 = this->getImageToBytes(dir + "/" + filename)->toBase64();


            std::cout << filename.toStdString() << " Size: " << imgToBase64.size() << std::endl;

            std::bitset<32> pointer = menMan->allocate(imgToBase64.size());
            QByteArray * toAllocate = static_cast<QByteArray *>(menMan->dereference(pointer));
            *toAllocate = imgToBase64;


            this->photos->AddEnd(pointer);
            ui->list_imgs->addItem(filename);

        }
}

void Launcher::on_action_Exit_triggered()
{
    this->close();
}

QByteArray * Launcher::getImageToBytes(QString file) {
    QImage img_enrll;
    img_enrll.load(file);
    QByteArray *arr;
    QBuffer buffer(arr);
    buffer.open(QIODevice::WriteOnly);
    img_enrll.save(&buffer, "JPEG");
    return arr;
}


void Launcher::on_list_imgs_currentRowChanged(int currentRow)
{
    QByteArray * imgToGet = static_cast<QByteArray *>(menMan->dereference(photos->getValue(currentRow)));
    //QByteArray tempArr = *imgToGet;
    std::cout << imgToGet->data() << std::endl;

    //QImage img = QImage::loadFromData();
    //QImage imgNew(dir + "/" + "ordinary-morning (2).jpg");
    QPixmap image;
    QByteArray *ba = imgToGet;
    image.loadFromData(*ba);
    ui->label_imgPrev->setPixmap(image);
}
