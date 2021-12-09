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
    QString strReply = static_cast<QString>(reply.readAll());
    QJsonDocument doc = QJsonDocument::fromJson(strReply.toUtf8());
    QJsonObject json = doc.object();

    int userId = json.value("userId").toInt();
    int id = json.value("id").toInt();
    QString title = json.value("title").toString();
    QString body = json.value("body").toString();
    unique_ptr<ForumPost> post = make_unique<ForumPost>(userId, id, title.toStdString(), body.toStdString());

    return post;
}

unique_ptr<ForumComment> Client::parseComment(QNetworkReply &reply) {
    QString strReply = static_cast<QString>(reply.readAll());
    QJsonDocument doc = QJsonDocument::fromJson(strReply.toUtf8());
    QJsonObject json = doc.object();

    int postId = json.value("postId").toInt();
    int id = json.value("id").toInt();
    QString name = json.value("name").toString();
    QString body = json.value("body").toString();
    QString email = json.value("email").toString();
    unique_ptr<ForumComment> comment = make_unique<ForumComment>(postId, id, name.toStdString(), email.toStdString(), body.toStdString());

    return comment;
}

Client::Client(QObject *parent) {
    networkManager = new QNetworkAccessManager(this);
    connect(networkManager, SIGNAL(finished(QNetworkReply *)), this, SLOT(onResult(QNetworkReply *)));
}

Client::~Client(void) {
    delete networkManager;
}

unique_ptr<ForumPost> Client::request(unsigned int postId) {
    QNetworkRequest *request = new QNetworkRequest;
    QNetworkReply *reply;

    request->setUrl(QUrl("http://jsonplaceholder.typicode.com/posts/" + QString::number(postId)));
    reply = networkManager->get(*request);
    blockUntilReplyReceived(reply);

    if (reply->error() != QNetworkReply::NoError) {
        qWarning() << reply->errorString();
        return nullptr;
    }
    delete request;
    return parseJson(*reply);
}

unique_ptr<ForumComment> Client::comment(unsigned int commentId) {
    QNetworkRequest *request = new QNetworkRequest;
    QNetworkReply *reply;

    request->setUrl(QUrl("http://jsonplaceholder.typicode.com/comments/" + QString::number(commentId)));
    reply = networkManager->get(*request);
    blockUntilReplyReceived(reply);

    if (reply->error() != QNetworkReply::NoError) {
        qWarning() << reply->errorString();
        return nullptr;
    }
    delete request;
    return parseComment(*reply);
}
