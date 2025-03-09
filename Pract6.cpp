#include<iostream>
#include<cstdlib>

using namespace std;

// program to print memory information 
int main(){
	cout<<"--------- Memory Information --------- "<<endl;
	system("free -h | head -4 > sysinfo.txt");

	system("cat sysinfo.txt");
	return 0;
}

