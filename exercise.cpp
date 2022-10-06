#include "exercise.h"
#include "ui_exercise.h"

exercise::exercise(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::exercise)
{
    qDebug()<<"调用exercise构造";
    ui->setupUi(this);
    readConfig();
    initWindow();
}

exercise::~exercise()
{
    qDebug()<<"调用exercise析构";
    movie->deleteLater();
    movie1->deleteLater();
    drink->deleteLater();
    delete ui;
}

void exercise::keyPressEvent(QKeyEvent *event){
    qDebug()<<"键盘捕捉";
    if(event->key() == Qt::Key_Escape){
        qDebug()<<"键盘捕捉到esc";
        player->stop();
        emit terminateRest();
//        this->close();
//        this->~exercise();
    }
    QWidget::keyPressEvent(event);
}

void exercise::initWindow(){
    ui->text_label->setScaledContents(true);
    setWindowState(Qt::WindowMaximized);
    setWindowFlags(Qt::FramelessWindowHint);
    setWindowFlags(Qt::WindowStaysOnTopHint);
//    setAttribute(Qt::WA_TranslucentBackground);
    setWindowOpacity(0.7); //设置窗体透明度
    this->setFocus(Qt::ActiveWindowFocusReason);
    playGif();
    prepareMusic();
}

void exercise::playGif(){
    if(movie == nullptr) movie = new QMovie("./assets/img/leftright.gif");
    if(movie1 == nullptr) movie1 = new QMovie("./assets/img/updown.gif");
    if(drink == nullptr) drink = new QMovie("./assets/img/drink.gif");
    ui->label->setMovie(movie);
    ui->label_2->setMovie(movie1);
    ui->label_3->setMovie(drink);
    movie->start();
    movie1->start();
    drink->start();
    ui->label->show();
    ui->label_2->show();
    ui->label_3->show();
    qDebug()<<"gif";
}

void exercise::prepareMusic(){
    player = new QMediaPlayer(this);
    qDebug() << musicDir + musicName;
    player->setMedia(QUrl::fromLocalFile(musicDir + musicName));
    player->setVolume(volume);
}

void exercise::playMusic(){
    player->play();
}
void exercise::closeEvent(QCloseEvent *event){
    event->ignore();
    this->hide();
    player->stop();

}
void exercise::readConfig(){
    QFile conf_file(conf_path);
    if(!conf_file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(this,tr("error"),tr("打开配置文件失败"),tr("OK"));
        return;
    }
    QByteArray ba = conf_file.readAll();
    conf_file.close();
    QJsonDocument doc = QJsonDocument::fromJson(ba);
    QJsonObject obj = doc.object();
    conf_file.close();
    volume = obj.value("volume").toInt();
    musicName = obj.value("musicPath").toString();
    qDebug() << musicName << volume;
}

