/* Web client Qt JSON
 * Tanner Babcock
 * tababcock@dmacc.edu
 * December 7, 2021 */
#include <QCoreApplication>
#include <iostream>
#include "client.h"
using namespace std;

int main(int argc, char *argv[]) {
    QCoreApplication a(argc, argv);
    Client client;

    unsigned int postId;
    cout << "What is the ID of the forum post you wish to view (0 to quit)? ";
    cin >> postId;
    while (postId != 0) {
        unique_ptr<ForumPost> post = client.request(postId);
        cout << "Title: " << post->getTitle() << endl;
        cout << post->getBody() << endl;
        cout << endl << "What is the ID of the forum post you wish to view (0 to quit)? ";
        cin >> postId;
    }
    return 0;
}
