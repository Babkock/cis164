/* Web client Qt JSON
 * Tanner Babcock
 * tababcock@dmacc.edu
 * December 7, 2021 */
#include <iostream>
#include <memory>
#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QDebug>
#include <QJsonObject>
#include <QJsonDocument>
#include "client.h"
using namespace std;

/* A QEventLoop can be used to wait in a loop until the server responds */
void Client::blockUntilReplyReceived(QNetworkReply *reply) {
    QEventLoop loop;
    connect(reply, SIGNAL(finished()), &loop, SLOT(quit()));
    loop.exec();
}

/* The server replies with a JSON object, to be useful, we want to map
 * that JSON object into a C++ object */
unique_ptr<ForumPost> Client::parseJson(QNetworkReply &reply) {
    QString strReply = (QString)reply.readAll();
    QJsonDocument doc = QJsonDocument::fromJson(strReply.toUtf8());
    QJsonObject json = doc.object();

    int userId = json.value("userId").toInt();
    int id = json.value("id").toInt();
    QString title = json.value("title").toString();
    QString body = json.value("body").toString();
    unique_ptr<ForumPost> post = make_unique<ForumPost>(userId, id, title.toStdString(), body.toStdString());
    return post;
}

Client::Client(QObject *parent) {
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, SIGNAL(finished(QNetworkReply *)), this, SLOT(onResult(QNetworkReply *)));
}

Client::~Client(void) {
    delete networkManager;
}

unique_ptr<ForumPost> Client::request(unsigned int postId) {
    QNetworkRequest request;
    QNetworkReply *reply;

    request.setUrl(QUrl("http://jsonplaceholder.typicode.com/posts/" + QString::number(postId)));
    reply = networkManager->get(request);
    blockUntilReplyReceived(reply);

    if (reply->error() != QNetworkReply::NoError) {
        qDebug() << reply->errorString();
        return nullptr;
    }
    return parseJson(*reply);
}
