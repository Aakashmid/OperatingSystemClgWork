#include <iostream>
#include <unistd.h>
using namespace std;

int main() {
    pid_t pid = fork();

    if (pid < 0) {
        cout<< "Fork failed.\n";
        
    }

    // Both parent and child will execute this code
    cout << "Process ID: " << getpid() << " - Running same code\n";

    return 0;
}

