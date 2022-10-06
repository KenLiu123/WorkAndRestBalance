#include "rest.h"
#include "ui_rest.h"
#define MtoS 60
rest::rest(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::rest)
{
    ui->setupUi(this);
    initApp();
    setTimeMap();
    writeConfig();
    readConfig();

}

rest::~rest()
{
    qDebug()<<"调用rest析构";
    delete ui;
}
void rest::initApp(){
    ui->pushButton_3->setStyleSheet("border-top:none;text-decoration:underline;");
    QStyledItemDelegate* styledItemDelegate = new QStyledItemDelegate();
    ui->restBox->setItemDelegate(styledItemDelegate);
    ui->work_Box->setItemDelegate(styledItemDelegate);
}

void rest::sysTrayIcon(QSystemTrayIcon::ActivationReason reason){
    switch (reason) {
    case QSystemTrayIcon::DoubleClick:
        this->show();
        m_sysTrayIcon->hide();
        break;
    default:
        break;
    }
}

void rest::createMenu(){
    if(m_menu == nullptr) m_menu = new QMenu(this);
    m_showWindow = new QAction(tr("显示主界面"),this);
    connect(m_showWindow, SIGNAL(triggered()), this, SLOT(slotShowWindow()));
    m_menu->addAction(m_showWindow);
    m_menu->addSeparator();
    m_closeWindow = new QAction(tr("退出"),this);
    connect(m_closeWindow, SIGNAL(triggered()), this, SLOT(slotcloseWindow()));
    m_menu->addAction(m_closeWindow);
    m_sysTrayIcon->setContextMenu(m_menu);
}

void rest::changeMenuAction(){
    if(isRunning){
        QList<QAction*> actionList = m_menu->actions();
        if(actionList.contains(m_continue)){
            m_menu->removeAction(m_continue);
            actionList.removeOne(m_continue);
            m_continue->deleteLater();
        }
        m_pauseRun = new QAction(tr("暂停"),this);
        connect(m_pauseRun, SIGNAL(triggered()), this, SLOT(slotPauseRun()));
        actionList.insert(1,m_pauseRun);
        m_menu->addActions(actionList);
        m_sysTrayIcon->setContextMenu(m_menu);
    }else{
        QList<QAction*> actionList = m_menu->actions();
        if(actionList.contains(m_pauseRun)){
            m_menu->removeAction(m_pauseRun);
            actionList.removeOne(m_pauseRun);
            m_pauseRun->deleteLater();
        }
        m_continue = new QAction(tr("继续"),this);
        connect(m_continue, SIGNAL(triggered()), this, SLOT(slotContinueRun()));
        actionList.insert(1,m_continue);
        m_menu->addActions(actionList);
        m_sysTrayIcon->setContextMenu(m_menu);

    }
}

void rest::writeConfig(){
    QFile conf_file(conf_path);
    if(!conf_file.exists()){
        QVariantHash subdata;
        subdata.insert("hasMusic", true);
        subdata.insert("volume", 20);
        subdata.insert("autoRun", false);
        subdata.insert("musicPath", "./assets/music/music001.mp3");
        subdata.insert("isRemember", false);
        subdata.insert("lastTimeval", 3600);
        subdata.insert("lastRestval", 300);
        QJsonObject obj = QJsonObject::fromVariantHash(subdata);
        QJsonDocument doc;
        doc.setObject(obj);
        QByteArray json_array = doc.toJson(QJsonDocument::Compact);

        if(!conf_file.open(QIODevice::ReadWrite | QIODevice::Text | QIODevice::Truncate)){
            QMessageBox::information(this,tr("error"),tr("保存配置文件失败"),tr("OK"));
            conf_file.close();
            return;
        }
        QTextStream stream(&conf_file);
        QString str(json_array);
        stream << str;
        conf_file.close();
    }
}
void rest::modifyConfig(){
    QFile conf_file(conf_path);
    if(!conf_file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(this,tr("error"),tr("保存配置文件失败"),tr("OK"));
        conf_file.close();
        return;
    }
    QByteArray ba = conf_file.readAll();
    conf_file.close();
    QJsonDocument doc = QJsonDocument::fromJson(ba);
    QJsonObject obj = doc.object();
    bool old1 = obj.value("isRemember").toBool();
    int old2 = obj.value("lastTimeval").toInt();
    int old3 = obj.value("lastRestval").toInt();
    if(old1 != isRemember){
        obj["isRemember"] = isRemember;
    }
    if(old2 != m_worktime){
        obj["lastTimeval"] = m_worktime;
    }
    if(old3 != m_resttime){
        obj["lastRestval"] = m_resttime;
    }
    if(!conf_file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)){
        QMessageBox::information(this,tr("error"),tr("保存配置文件失败"),tr("OK"));
        conf_file.close();
        return;
    }
    QJsonDocument doc1;
    doc1.setObject(obj);
    QByteArray json_array = doc1.toJson(QJsonDocument::Compact);
    QTextStream stream(&conf_file);
    QString str(json_array);
    stream << str;
    conf_file.close();

}

void rest::readConfig(){
    QFile conf_file(conf_path);

    if(!conf_file.open(QIODevice::ReadOnly | QIODevice::Text)){
        QMessageBox::information(this,tr("error"),QString("打开配置文件失败\n"),tr("OK"));
        conf_file.close();
        return;
    }
    QByteArray ba = conf_file.readAll();
    conf_file.close();
    QJsonDocument doc = QJsonDocument::fromJson(ba);
    QJsonObject obj = doc.object();

    isRemember = obj.value("isRemember").toBool();
    hasMusic = obj.value("hasMusic").toBool();
    if(isRemember){
        ui->checkBox->setChecked(true);
    }
    int t1 = obj.value("lastTimeval").toInt();
    m_worktime = t1;
    for(QMap<QString,int>::iterator it = m_work.begin(); it != m_work.end(); it++){
        if(it.value() == t1){
            ui->work_Box->setCurrentText(it.key());
            break;
        }
    }
    int t2 = obj.value("lastRestval").toInt();
    m_resttime = t2;
    for(QMap<QString,int>::iterator it = m_rest.begin(); it != m_rest.end(); it++){
        if(it.value() == t2){
            ui->restBox->setCurrentText(it.key());
            break;
        }
    }
}
void rest::setTimeMap(){
    m_work.insert("0.5小时",  30 * MtoS);
    m_work.insert("1小时",    60 * MtoS);
    m_work.insert("1.5小时",  90 * MtoS);
    m_work.insert("2小时",   120 * MtoS);
    m_work.insert("2.5小时", 150 * MtoS);

    m_rest.insert("5分钟",   5 * MtoS);
    m_rest.insert("10分钟", 10 * MtoS);
    m_rest.insert("15分钟", 15 * MtoS);
    m_rest.insert("20分钟", 20 * MtoS);
}

void rest::closeEvent(QCloseEvent *event){
    QMessageBox::StandardButton button;
    button = QMessageBox::question(this,tr("exit"),tr("Do you really want exit?"),QMessageBox::Yes|QMessageBox::No);
    if (button==QMessageBox::Yes)
    {
        event->accept();
    }else{
        event->ignore();
    }
}

void rest::slotShowWindow(){
    this->show();
    m_sysTrayIcon->hide();
}

void rest::slotcloseWindow(){
    this->~rest();
    exit(0);
}


void rest::on_pushButton_2_clicked()
{
    if ((QMessageBox::information(this,tr("exit"),tr("Do you really want exit?"),tr("Yes"),tr("No"))))
    {
        return;
    }
    exit(0);
}

void rest::trayIconUtils()
{
    if(m_sysTrayIcon == nullptr) m_sysTrayIcon = new QSystemTrayIcon(this);
    QIcon icon("./assets/img/icon.svg");
    m_sysTrayIcon->setIcon(icon);
    connect(m_sysTrayIcon, SIGNAL(activated(QSystemTrayIcon::ActivationReason)),
            this, SLOT(sysTrayIcon(QSystemTrayIcon::ActivationReason)));
    createMenu();
    m_sysTrayIcon->show();
}

void rest::initTimerThread(){
    if(!t_thread) t_thread = new TimeThread();
    connect(t_thread, SIGNAL(startRestSignal()), this, SLOT(slotStartRest()),Qt::QueuedConnection);
    connect(t_thread, SIGNAL(startWorkSignal()), this, SLOT(slotStartWork()),Qt::QueuedConnection);
    connect(this, SIGNAL(skipRestSignal()), t_thread, SLOT(skipSlot()));
    connect(t_thread, SIGNAL(runOneSecond()), this, SLOT(slotRunSecond()),Qt::QueuedConnection);
    connect(this, SIGNAL(stopTimer()),t_thread, SLOT(stopTimerSlot()));
    connect(this, SIGNAL(runTimer()),t_thread, SLOT(runTimerSlot()));
}

void rest::on_pushButton_clicked()
{
    duringTime = 0;
    initTimerThread();
    QString index_t1 = ui->work_Box->currentText();
    QString index_t2 = ui->restBox->currentText();
    m_worktime = m_work[index_t1];
    m_resttime = m_rest[index_t2];
    qDebug() << m_worktime <<"-" << m_resttime;
    t_thread->runTimeVal(m_worktime, m_resttime);
    if(ui->checkBox->checkState() == Qt::Checked){
        isRemember = true;
    }

    if(isRemember) modifyConfig();
    this->hide();
    trayIconUtils();
    t_thread->start();
    isRunning = true;
    changeMenuAction();
}

void rest::drawToolTip(){
    int min = 0,sec = duringTime % 60;
    if(duringTime > 60){
        min = duringTime / 60;
    }
    m_sysTrayIcon->setToolTip(QString("rest\n正在运行...\n已连续工作\n%1分%2秒\n当前定时%3分").arg(min).arg(sec).arg(m_worktime / 60));
}

void rest::slotRestTerminated(){
    emit skipRestSignal();
    duringTime = 0;
}

void rest::on_pushButton_3_clicked()
{
    if(m_setting == nullptr) m_setting = new setting(this);
    m_setting->show();
    m_setting->setAttribute(Qt::WA_DeleteOnClose);
    connect(m_setting, &setting::destroyed, this, [=](){
        m_setting= nullptr;
    });
}

void rest::slotContinueRun()
{
    isRunning = true;
    changeMenuAction();
    emit runTimer();
    duringTime = 0;
}

void rest::slotPauseRun()
{
    isRunning = false;
    changeMenuAction();
    emit stopTimer();
    qDebug()<<"暂停";
    m_sysTrayIcon->setToolTip(QString("rest\n已暂停"));
}

void rest::slotStartRest()
{
    duringTime = 0;
    if(exerc == nullptr) {
        exerc = new exercise(this);
        exerc->setWindowFlags(Qt::Window);
        connect(exerc, SIGNAL(terminateRest()), this, SLOT(slotRestTerminated()));
    }
    exerc->show();
    if(hasMusic) exerc->playMusic();
}

void rest::slotStartWork()
{
    duringTime = 0;
    exerc->close();
}

void rest::slotRunSecond()
{
    duringTime++;
    drawToolTip();
}
