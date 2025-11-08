#include <iostream>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
using namespace std;
void forkexample()
{
    // run child process when fork() is 0 else run parent process
    if (fork() == 0)
    {   
	cout<<"Hello from Child!\n";
        execlp("/bin/ls"," ",NULL); 
    }

    else{
	wait(NULL);   // for for child to complete its process
        cout<<"Hello from Parent!\n";    
    }
 }


 int main()
 {
    forkexample();
    return 0;
 }
