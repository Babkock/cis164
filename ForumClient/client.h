/* Web client Qt JSON
 * Tanner Babcock
 * tababcock@dmacc.edu
 * December 7, 2021 */
#ifndef CLIENT_H
#define CLIENT_H

#include <memory>
#include <QApplication>
#include <QNetworkAccessManager>
#include <QNetworkReply>

struct ForumPost {
    int userId;
    int id;
    std::string title;
    std::string body;
};

class Client : QObject {
Q_OBJECT
private:
    QNetworkAccessManager *networkManager;
    void blockUntilReplyReceived(QNetworkReply *reply);
    std::unique_ptr<ForumPost> parseJson(QNetworkReply &reply);
public:
    explicit Client(QObject *parent = nullptr);
    ~Client(void);
    std::unique_ptr<ForumPost> request(int postId);
signals:
public slots:
    void onResult(QNetworkReply *reply);
};

#endif // CLIENT_H
