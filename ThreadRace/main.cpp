/* Thread race bug
 * Tanner Babcock
 * tababcock@dmacc.edu
 * November 18, 2021 */
#include <iostream>
#include <array>
#include <cstdlib>
#include <QThread>
#include <QString>
#include <QDebug>
#include <QMutex>
using namespace std;

const int SIZE = 1000;

class SumThread : public QThread {
private:
    array<array<long, SIZE>, SIZE> &table;
    size_t startRow;
    size_t skipRows;
    static long total;
    static QMutex mutex;
public:
    SumThread(array<array<long, SIZE>, SIZE> &table, size_t st, size_t sk):
        table(table), startRow(st), skipRows(sk) {
        total = 0;
    }

    void run(void) {
        /* I gave this SumThread object a QMutex member. So only one thread can be calculating at a time
         * Without Mutex, the output was not in order, and the grand total was different each time */
        mutex.lock();
        cout << "Calculating table " << startRow << endl;
        for (size_t row = startRow; row < table.size(); row += skipRows) {
            long rowTotal = 0;
            for (size_t column = 0; column < table[0].size(); column++) {
                rowTotal += table[row][column];
            }
            total += rowTotal;
        }
        //sleep(1);
        // for illustrative purposes
        mutex.unlock();
    }

    static long getTotal(void) {
        return total;
    }
};

QMutex SumThread::mutex;
long SumThread::total;
extern array<array<long, SIZE>, SIZE> bigTable;
array<array<long, SIZE>, SIZE> bigTable;

int main(void) {
    for (size_t i = 0; i < bigTable.size(); i++) {
        for (size_t j = 0; j < bigTable[0].size(); j++) {
            bigTable[i][j] = static_cast<long>(i + j);
        }
    }
    for (int x = 0; x < 100; x++) {
        cout << "Round " << x << endl;
        SumThread *thread1 = new SumThread(bigTable, 0, 4);
        SumThread *thread2 = new SumThread(bigTable, 1, 4);
        SumThread *thread3 = new SumThread(bigTable, 2, 4);
        SumThread *thread4 = new SumThread(bigTable, 3, 4);

        thread1->start();
        thread2->start();
        thread3->start();
        thread4->start();

        thread1->wait();
        thread2->wait();
        thread3->wait();
        thread4->wait();

        delete thread1;
        delete thread2;
        delete thread3;
        delete thread4;

        cout << "Grand total: " << SumThread::getTotal() << endl;
    }
    return 0;
}
