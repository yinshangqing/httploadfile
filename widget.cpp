#include "widget.h"
#include "ui_widget.h"
#include "view_choose_windows.h"
#include "http_load_photo.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    CViewChooseWindows *viewChoose = new CViewChooseWindows(this);
    viewChoose->show();
//    CHttpLoadPhoto httpPhoto;

//    httpPhoto.downloadFileFromURL("http://172.21.0.12:9080/4,15fe292dba877c.jpg","D:\\MyWork\\test2.jpg");
    QNetworkRequest request;
    request.setUrl(QUrl("http://172.21.0.12:9080/4,15fe292dba877c.jpg"));
    connect(&m_networkManager, SIGNAL(finished(QNetworkReply *)), this, SLOT(replyFinished(QNetworkReply *)));
    m_networkManager.get(request);

//    QImage img;
////    img.load("http://172.21.0.12:9080/4,15fe292dba877c.jpg");
//    img.load("D:\\MyWork\\test2.jpg");
//    ui->label->setPixmap(QPixmap::fromImage(img));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::replyFinished(QNetworkReply *reply)
{
    // 获取响应状态码，200表示正常
    // QVariant nCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute);

    if (reply->error() == QNetworkReply::NoError)
    {
        QByteArray bytes = reply->readAll();
        QPixmap pixmap;
        pixmap.loadFromData(bytes);
        ui->label->setScaledContents(true);
        ui->label->setPixmap(pixmap);

        // 缓存到本地
        QFile file("D:/test.jpg");
        if (file.open(QIODevice::Append))
            file.write(bytes);
        file.close();
    }
    else
    {
        // 错误处理-显示错误信息，或显示上一次缓存的图片或叉图。
    }
}
