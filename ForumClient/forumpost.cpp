/* Web client Qt JSON
 * Tanner Babcock
 * tababcock@dmacc.edu
 * December 8, 2021 */
#include "client.h"

ForumPost::ForumPost(int uid, int i, std::string t, std::string b):
    userId(uid),
    id(i),
    title(t),
    body(b) { }

std::string ForumPost::getTitle(void) {
    return title;
}

void ForumPost::setTitle(const std::string &t) {
    title = t;
}

std::string ForumPost::getBody(void) {
    return body;
}

void ForumPost::setBody(const std::string &b) {
    body = b;
}
