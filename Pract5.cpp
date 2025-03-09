#include<iostream>
#include<cstdlib> // Provides the system() function to execute shell commands.
using namespace std;

int main(){
	cout<<"------- system kernel ----- " <<endl;
	system("uname -r ");  // system kernel information
	cout<<"---------- cpu information ---- \n";
	system("lscpu | head -8 > cpuinfo.txt");  // put data obtain from lscpu in cpuinfo.txt
	system("cat cpuinfo.txt");  // print cpuinf.txt  content on terminal 
	return 0;
}
