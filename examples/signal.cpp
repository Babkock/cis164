/* Signal handler
 * Tanner Babcock
 * October 25, 2021 */
#include <iostream>
#include <csignal>
#include <unistd.h>
using namespace std;

void signalHandler(int sig) {
	cout << endl << "Interrupt signal (" << sig << ") received" << endl;
	exit(sig);
}

int main(void) {
	signal(SIGINT, signalHandler);

	while (1) {
		cout << "Going to sleep." << endl;
		sleep(1);
	}

	return 0;
}

