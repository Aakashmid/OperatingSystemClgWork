#include <iostream>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;

int main() {
    int pid = fork();
    if (pid == 0) {
        // Child process
	cout << "Child  process PID : " << getpid() << endl;
        sleep(2); // Simulate task
    } else {
        // Parent process waits
        cout << "Parent processPID: " << getpid() << endl;
        wait(NULL);  // Wait for child to finish
        cout<< "Parent Child finished. Parent exiting.\n";
    }

    return 0;
}

