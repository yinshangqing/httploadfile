#ifndef HTTP_LOAD_PHOTO_H
#define HTTP_LOAD_PHOTO_H

#include <QObject>
#include <QFile>
#include <QtNetwork>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QObject>
#include <QUrl>

class CHttpLoadPhoto : public QObject
{
    Q_OBJECT
public:
    explicit CHttpLoadPhoto(QObject *parent = nullptr);
    ~CHttpLoadPhoto();

    void setUrl(QUrl url);


signals:
    void SIGNAL_sendShowPhoto(QPixmap &);
    void SIGNAL_sendError(QString);

private slots:
    void SLOT_replyFinished(QNetworkReply *);

private:
    QNetworkAccessManager m_networkManager;
    QNetworkRequest m_request;

};

#endif // HTTP_LOAD_PHOTO_H
