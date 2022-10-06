#ifndef TIMETHREAD_H
#define TIMETHREAD_H

#include <QObject>
#include <QThread>
#include <QTimer>

class TimeThread : public QThread
{
    Q_OBJECT
public:
    explicit TimeThread(QObject *parent = nullptr);
    virtual ~TimeThread();
    void run() ;
    void runTimeVal(long long wt, long long rt);
private:
    QTimer *m_timer = nullptr;
    long long m_worktime;
    long long m_resttime;
    long long endWork;
    long long endRest;
    bool isWorking;
    void timerUtil();
    void startRun();
signals:
    void startRestSignal();
    void startWorkSignal();
    void runOneSecond();
public slots:
    void update();
    void skipSlot();
    void stopTimerSlot();
    void runTimerSlot();
};

#endif // TIMETHREAD_H
