#ifndef REST_H
#define REST_H

#include <QWidget>
#include <QTime>
#include <QTimer>
#include <QCloseEvent>
#include <QMessageBox>
#include <QFile>
#include <QSystemTrayIcon>
#include <QMenu>
#include <QAction>
#include <QIcon>
#include <QDebug>
#include <QTextStream>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QVariantHash>
#include <QMap>
#include <string>
#include <QEventLoop>
#include <QDateTime>
#include <QStyledItemDelegate>
#include "exercise.h"
#include "setting.h"
#include "timethread.h"
namespace Ui {
class rest;
}

class rest : public QWidget
{
    Q_OBJECT

public:
    void setTimeMap();
    explicit rest(QWidget *parent = 0);
    ~rest();
    //void setTimeVal();
    QMap<QString, int> m_work;
    QMap<QString, int> m_rest;
    int m_worktime, m_resttime;
    void closeEvent(QCloseEvent *event);
private slots:
    void on_pushButton_2_clicked();
    void on_pushButton_clicked();
    void sysTrayIcon(QSystemTrayIcon::ActivationReason reason);
    void slotShowWindow();
    void slotcloseWindow();
    //void slotTimeout();
    //void slotRestTimeout();
    void drawToolTip();
    void slotRestTerminated();
    void on_pushButton_3_clicked();
    void slotContinueRun();
    void slotPauseRun();
    void slotStartRest();
    void slotStartWork();
    void slotRunSecond();
private:
    bool isRemember,hasMusic,isRunning;
    Ui::rest *ui;
    //QTimer* m_timer = nullptr;
    //QTime* m_time = nullptr;
    const QString conf_path = "./assets/conf.json";
    QSystemTrayIcon *m_sysTrayIcon = nullptr;
    QMenu *m_menu = nullptr;
    QAction *m_showWindow = nullptr;
    QAction *m_closeWindow = nullptr;
    QAction *m_pauseRun = nullptr;
    QAction *m_continue = nullptr;
    exercise *exerc = nullptr;
    setting *m_setting = nullptr;
    TimeThread *t_thread = nullptr;
    int duringTime;
    int endWorkTime;
    int endRestTime;
    void readConfig();
    void writeConfig();
    void initApp();
    void timerUtil();
    void createMenu();
    void startRun();
    void modifyConfig();
    void changeMenuAction();
    void autoStart();
    void trayIconUtils();
    void initTimerThread();
signals:
    void runTimer();
    void stopTimer();
    void skipRestSignal();
};

#endif // REST_H
