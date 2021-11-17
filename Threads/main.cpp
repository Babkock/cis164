#include <iostream>
#include <QThread>
#include <QString>
#include <QDebug>
#include <QMutex>
using namespace std;

class HelloThread : public QThread {
private:
    QString threadId;
    static QMutex mutex;
public:
    explicit HelloThread(QString s): threadId(s) { }

    void run(void) {
        mutex.lock();
        cout << "Hello world from thread " << threadId.toStdString() << "!" << endl;
        mutex.unlock();
    }
};

QMutex HelloThread::mutex;

int main(void) {
    // create the threads
    HelloThread thread1("A");
    HelloThread thread2("B");
    HelloThread thread3("C");

    // start the threads
    thread1.start();
    thread2.start();
    thread3.start();

    thread1.wait();
    thread2.wait();
    thread3.wait();

    return 0;
}
