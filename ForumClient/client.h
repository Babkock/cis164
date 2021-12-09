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

class ForumPost {
private:
    int userId;
    int id;
    std::string title;
    std::string body;
public:
    ForumPost(int uid, int i, const std::string &t, const std::string &b);
    int getUserId(void);
    int getId(void);
    std::string getTitle(void);
    void setTitle(const std::string &t);
    std::string getBody(void);
    void setBody(const std::string &b);
};

class ForumComment {
private:
    int postId;
    int id;
    std::string name;
    std::string email;
    std::string body;
public:
    ForumComment(int pid, int i, const std::string &n, const std::string &e, const std::string &b);
    int getPostId(void);
    int getId(void);
    std::string getName(void);
    void setName(const std::string &n);
    std::string getEmail(void);
    void setEmail(const std::string &e);
    std::string getBody(void);
    void setBody(const std::string &b);
};

class Client : QObject {
Q_OBJECT
private:
    QNetworkAccessManager *networkManager;
    void blockUntilReplyReceived(QNetworkReply *reply);
    std::unique_ptr<ForumPost> parseJson(QNetworkReply &reply);
    std::unique_ptr<ForumComment> parseComment(QNetworkReply &reply); /* Json for Forum Comment */
public:
    explicit Client(QObject *parent = nullptr);
    ~Client(void);
    std::unique_ptr<ForumPost> request(unsigned int postId);
    std::unique_ptr<ForumComment> comment(unsigned int commentId); /* new function */
signals:
public slots:
    void onResult(QNetworkReply *reply) { }
};

#endif // CLIENT_H
