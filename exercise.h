#ifndef EXERCISE_H
#define EXERCISE_H
#include <QDebug>
#include <QWidget>
#include <QMovie>
#include <QKeyEvent>
#include <QSound>
#include <QtMultimedia\QMediaPlayer>
#include <QCloseEvent>
#include <QMessageBox>
#include <QJsonDocument>
#include <QJsonObject>
#include <QObject>
namespace Ui {
class exercise;
}

class exercise : public QWidget
{
    Q_OBJECT

public:
    explicit exercise(QWidget *parent = 0);
    void closeEvent(QCloseEvent *event);
    ~exercise();
    void playMusic();
private:
    Ui::exercise *ui;
    void initWindow();
//    QKeyEvent *event;
    void keyPressEvent(QKeyEvent *event);
//    void keyReleaseEvent(QKeyEvent *event);
    void playGif();
    void prepareMusic();
    QMediaPlayer* player;
    QMovie *movie = nullptr;
    QMovie *movie1 = nullptr;
    QMovie *drink = nullptr;
    const QString conf_path = "./assets/conf.json";
    const QString musicDir = "./assets/music/";
    QString musicName;
    int volume;
    void readConfig();
signals:
    void terminateRest();
};

#endif // EXERCISE_H
