#include "setting.h"
#include "ui_setting.h"
#include <QDebug>
#define AUTO_RUN "HKEY_CURRENT_USER\\Software\\Microsoft\\Windows\\CurrentVersion\\Run"
setting::setting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::setting)
{
    player = nullptr;
    playing = false;
    ui->setupUi(this);
    readMusicDir();
    adjustVolume();
    readConfig();
    setConfig();

}

setting::~setting()
{
    qDebug()<<"析构setting";
    delete player;
    player = nullptr;
    delete ui;
}

void setting::readMusicDir(){

    ui->ListView->setAlternatingRowColors(true);
    QStandardItemModel *model = new QStandardItemModel(this);
    QDir dir(musicDir);
    dir.setFilter(QDir::Files);
    dir.setSorting(QDir::Name);
    m_list = dir.entryInfoList();
    for(int i = 0; i < m_list.size(); i++){
        QFileInfo info = m_list[i];
        qDebug() << QString("音乐文件%1:").arg(i) << info.fileName();
        QStandardItem *item = new QStandardItem(info.fileName());
        model->appendRow(item);
    }
    ui->ListView->setModel(model);
    connect(ui->ListView, SIGNAL(doubleClicked(QModelIndex)), this, SLOT(slot_item_doubleClicked(QModelIndex)));

}

void setting::on_pushButton_play_clicked()
{
    qDebug()<< "playing" <<playing;
    if(playing){
        QIcon icon("./assets/img/noplay.svg");
        ui->pushButton_play->setIcon(icon);
        stopMusic();
    }else{
        QIcon icon("./assets/img/play.svg");
        ui->pushButton_play->setIcon(icon);
        QModelIndex idx = ui->ListView->currentIndex();
        QString name = idx.data().toString();
        QString path = musicDir + name;
        prepareMusic(path);
        playMusic();
    }
}

void setting::prepareMusic(QString path){
    if(player == nullptr) player = new QMediaPlayer(this);
    player->setMedia(QUrl::fromLocalFile(path));
    player->setVolume(ui->label_2->text().toInt());
}

void setting::playMusic(){
    player->play();
    playing = true;
}
void setting::stopMusic(){
    if(playing) {
        player->stop();
        playing = false;
    }
}

void setting::slot_item_doubleClicked(QModelIndex index){
    QIcon icon("./assets/img/play.svg");
    ui->pushButton_play->setIcon(icon);
    QString path = musicDir + (index.data().toString());
    qDebug()<<"current music path" << path;
    prepareMusic(path);
    playMusic();
}
void setting::adjustVolume(){
    ui->horizontalSlider->setRange(0,100);
    ui->horizontalSlider->setValue(20);
    ui->label_2->setText(QString::number(ui->horizontalSlider->value()));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)),this,SLOT(slot_changeLabel(int)));

}
void setting::slot_changeLabel(int val){
    ui->label_2->setText(QString::number(val));
    if(playing){
        player->setVolume(ui->label_2->text().toInt());
    }
}

void setting::on_pushButton_save_clicked()
{
    struct settingItem s;
    if(ui->checkBox->checkState() == Qt::Checked){
        s.hasMusic = true;
    }else{
        s.hasMusic = false;
    }
    s.musicPath = ui->ListView->currentIndex().data().toString();
    s.volume = ui->horizontalSlider->value();
    if(ui->checkBox_2->checkState() == Qt::Checked){
        s.autoRun = true;
        setAutoRun();
    }else{
        s.autoRun = false;
        cancelAutoRun();
    }
    writeConfig(s);
    stopMusic();
    debugPrint(s);
    this->close();
}

void setting::readConfig(){
    QFile conf_file(conf_path);
    if(!conf_file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(this,tr("error"),tr("打开配置文件失败"),tr("OK"));
        return;
    }
    QByteArray ba = conf_file.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(ba);
    obj = doc.object();
    conf_file.close();
}

void setting::writeConfig(settingItem s){
    bool old1 = obj.value("hasMusic").toBool();
    int old2 = obj.value("volume").toInt();
    bool old3 = obj.value("autoRun").toBool();
    QString old4 = obj.value("hasMusic").toString();
    if(old1 != s.hasMusic){
        obj["hasMusic"] = s.hasMusic;
    }
    if(old2 != s.hasMusic){
        obj["volume"] = s.volume;
    }
    if(old3 != s.autoRun){
        obj["autoRun"] = s.autoRun;
    }
    if(old4 != s.musicPath){
        obj["musicPath"] = s.musicPath;
    }
    QJsonDocument doc;
    doc.setObject(obj);
    QByteArray json_array = doc.toJson(QJsonDocument::Compact);
    QFile conf_file(conf_path);
    if(!conf_file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)){
        QMessageBox::information(this,tr("error"),tr("保存配置文件失败"),tr("OK"));
        return;
    }
    QTextStream stream(&conf_file);
    QString str(json_array);
    stream << str;
    conf_file.close();
}
void setting::setConfig(){
    ui->checkBox->setChecked(obj.value("hasMusic").toBool());
    ui->horizontalSlider->setValue(obj.value("volume").toInt());
    ui->checkBox_2->setChecked(obj.value("autoRun").toBool());
    QModelIndex mdx;
    for(int i = 0; i < m_list.size(); i++){
        if(m_list[i].fileName() == obj.value("musicPath").toString()){
            mdx = ui->ListView->model()->index(i, 0);
            ui->ListView->setCurrentIndex(mdx);
        }
    }

}
void setting::setAutoRun(){
    setProcessAutoRun(QApplication::applicationFilePath(),1);
}
void setting::cancelAutoRun(){
    setProcessAutoRun(QApplication::applicationFilePath(),0);
}

void setting::setProcessAutoRun(const QString &appPath,bool flag)
{
    QSettings settings(AUTO_RUN, QSettings::NativeFormat);

    //以程序名称作为注册表中的键,根据键获取对应的值（程序路径）
    QFileInfo fInfo(appPath);
    QString name = fInfo.baseName();    //键-名称

    //如果注册表中的路径和当前程序路径不一样，则表示没有设置自启动或本自启动程序已经更换了路径
    QString oldPath = settings.value(name).toString(); //获取目前的值-绝对路劲
    QString newPath = QDir::toNativeSeparators(appPath);    //toNativeSeparators函数将"/"替换为"\"
    if(flag)
    {
        if (oldPath != newPath)
            settings.setValue(name, newPath);
    }
    else
        settings.remove(name);
}

void setting::debugPrint(struct settingItem s)
{
    qDebug()<< "auto run:" << s.autoRun;
    qDebug()<< "has music:" << s.hasMusic;
    qDebug()<< "music path:" << s.musicPath;
    qDebug()<< "volume:" << s.volume;
}

void setting::on_pushButton_cancel_clicked()
{

    stopMusic();
    this->close();
}


