#include<iostream>
#include<unistd.h>
#include<sys/wait.h>
using namespace std;


// child and parent  run different code
int main(){
	int p=fork();
	if(p==0){
		cout<<"Child process is running... \nCurrent process id is : "<<getpid()<<endl;
		cout<<"Parent process id "<<getppid()<<endl;
		sleep(5);
	}
	else{
		wait(NULL);  // wait for child process to complete
		cout<<"Parent process is running... \n";
		cout<<"Current process id is : "<<getpid()<<endl;;
		cout<<p<<endl;  // print p value which is child process id 
	}

	return 0;
}

