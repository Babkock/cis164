/* Web client Qt JSON
 * Tanner Babcock
 * tababcock@dmacc.edu
 * December 8, 2021 */
#include "client.h"

ForumComment::ForumComment(int pid, int i, const std::string &n, const std::string &e, const std::string &b):
    postId(pid),
    id(i),
    name(n),
    email(e),
    body(b) { }

int ForumComment::getPostId(void) {
    return postId;
}

int ForumComment::getId(void) {
    return id;
}

std::string ForumComment::getName(void) {
    return name;
}

void ForumComment::setName(const std::string &n) {
    name = n;
}

std::string ForumComment::getEmail(void) {
    return email;
}

void ForumComment::setEmail(const std::string &e) {
    email = e;
}

std::string ForumComment::getBody(void) {
    return body;
}

void ForumComment::setBody(const std::string &b) {
    body = b;
}
