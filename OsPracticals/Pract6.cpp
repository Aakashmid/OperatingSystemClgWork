#include<iostream>
#include<cstdlib>

using namespace std;

// program to print memory information 
int main(){
	cout<<"--------- Memory Information --------- "<<endl;
	// write last 4 line of  data obatian from free -h command to sysinfo.txt
	system("free -h | head -4 > sysinfo.txt");

	system("cat sysinfo.txt"); // print sysinfo.txt content
	return 0;
}

