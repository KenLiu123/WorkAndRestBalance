#ifndef SETTING_H
#define SETTING_H

#include <QDialog>
#include <QDir>
#include <QFile>
#include <QtMultimedia\QMediaPlayer>
#include <QFileInfoList>
#include <QStandardItem>
#include <QStandardItemModel>
#include <QVariantHash>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonParseError>
#include <QFile>
#include <QString>
#include <QMessageBox>
#include <QDir>
#include <QSettings>
namespace Ui {
class setting;
}

class setting : public QDialog
{
    Q_OBJECT

public:
    explicit setting(QWidget *parent = 0);
    struct settingItem{
        bool hasMusic;
        QString musicPath;
        int volume;
        bool autoRun;
    };

    ~setting();

private slots:
    void on_pushButton_play_clicked();
    void slot_item_doubleClicked(QModelIndex index);
    void slot_changeLabel(int val);

    void on_pushButton_cancel_clicked();

    void on_pushButton_save_clicked();

private:
    Ui::setting *ui;
    const QString conf_path = "./assets/conf.json";
    const QString musicDir = "./assets/music/";
    void readMusicDir();
    bool playing;
    QMediaPlayer *player;
    QJsonObject obj;
    QFileInfoList m_list;
    void prepareMusic(QString path);
    void playMusic();
    void stopMusic();
    void adjustVolume();
    void writeConfig(settingItem s);
    void readConfig();
    void setConfig();
    void setAutoRun();
    void cancelAutoRun();
    void setProcessAutoRun(const QString &appPath,bool flag);
    void debugPrint(struct settingItem s);
};

#endif // SETTING_H
