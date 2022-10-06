#include "timethread.h"
#include <QDebug>

TimeThread::TimeThread(QObject *parent) : QThread(parent)
{
    moveToThread(this);
}
TimeThread::~TimeThread(){
    m_timer->deleteLater();
}

void TimeThread::run()
{
    qDebug()<< "开始";
    endWork = m_worktime;
    endRest = m_resttime;
    isWorking = true;
    if(m_timer == nullptr) m_timer = new QTimer();
    m_timer->start(1000);
    connect(m_timer, SIGNAL(timeout()), this, SLOT(update()), Qt::DirectConnection);
    this->exec();
}

void TimeThread::runTimeVal(long long wt, long long rt)
{
    this->m_worktime = wt;
    this->m_resttime = rt;
}

void TimeThread::startRun(){
    qDebug()<< "计时开始";
}
void TimeThread::update(){
    emit runOneSecond();
    if(isWorking) endWork--;
    else endRest--;
    if(endWork <= 0){
        qDebug()<<"休息时间到";
        emit startRestSignal();
        isWorking = false;
        endWork = m_worktime;
    }
    if(endRest <= 0){
        qDebug()<<"工作时间到";
        emit startWorkSignal();
        isWorking = true;
        endRest = m_resttime;
    }
}

void TimeThread::skipSlot()
{
    emit startWorkSignal();
    isWorking = true;
    endRest = m_resttime;
}

void TimeThread::stopTimerSlot()
{
    m_timer->stop();
}

void TimeThread::runTimerSlot()
{
    endWork = m_worktime;
    endRest = m_resttime;
    isWorking = true;
    m_timer->start();
}












