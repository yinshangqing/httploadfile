#include "http_load_photo.h"

CHttpLoadPhoto::CHttpLoadPhoto(QObject *parent)
    : QObject(parent)
{
    connect(&m_networkManager, SIGNAL(finished(QNetworkReply *)), this, SLOT(SLOT_replyFinished(QNetworkReply *)));
}

CHttpLoadPhoto::~CHttpLoadPhoto()
{

}

void CHttpLoadPhoto::setUrl(QUrl url)
{
    m_request.setUrl(url);
    m_networkManager.get(m_request);
}

void CHttpLoadPhoto::SLOT_replyFinished(QNetworkReply *reply)
{
    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();
        QPixmap pixmap;
        pixmap.loadFromData(bytes);
        emit SIGNAL_sendShowPhoto(pixmap);
    }
    else
    {
        // 错误处理-显示错误信息，或显示上一次缓存的图片或叉图。
//        emit SIGNAL_sendError(reply->error());
    }
}
