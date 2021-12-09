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
    unsigned int id, choice;

    cout << "Would you like to view a (1: post) or (2: comment) ? ";
    cin >> choice;

    if (choice == 1) {
        cout << "What is the ID of the post you wish to view (0 to quit)? ";
        cin >> id;
        while (id != 0) {
            unique_ptr<ForumPost> post = client.request(id);
            if (post == nullptr) {
                return 2;
            }
            cout << "Title: " << post->getTitle() << endl;
            cout << "Body: " << post->getBody() << endl;
            cout << endl << "What is the ID of the forum post you wish to view (0 to quit)? ";
            cin >> id;
        }
    } else if (choice == 2) {
        cout << "What is the ID of the comment you wish to view (0 to quit)? ";
        cin >> id;
        while (id != 0) {
            unique_ptr<ForumComment> comment = client.comment(id);
            if (comment == nullptr) {
                return 2;
            }
            cout << "Name: " << comment->getName() << endl;
            cout << "Email: " << comment->getEmail() << endl;
            cout << "Body: " << comment->getBody() << endl;
            cout << endl << "What is the ID of the comment you wish to view (0 to quit)? ";
            cin >> id;
        }
    } else {
        cout << "Did not understand choice" << endl;
        return 1;
    }

    return 0;
}
