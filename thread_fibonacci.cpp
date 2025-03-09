#include<iostream>
#include<pthread.h>
using namespace std;


void* fibonacci(void* arg){
	int limit = *(int*)arg;  // Convert void* to int*
	int first=0;
	int second=1;
	int sum=0;
	cout<<"Fibonacci Series :";
	while(first<=limit){
		cout<<first<<" ";
		sum=first+second;
		first = second;
		second =  sum;
	}
	cout<<endl;
	return NULL;
}

int main(){
	cout<<"Enter limit of fibonacci series : ";
	int limit;
	cin>>limit;
	pthread_t thread;
	pthread_create(&thread,NULL,fibonacci,&limit);
	pthread_join(thread,NULL);
	return 0;
}


