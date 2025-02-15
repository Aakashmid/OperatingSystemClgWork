#include <stdio.h> 
#include <unistd.h> 
  
void forkexample() 
{ 
    int x = 1; 
  
    if (fork() == 0) 
        printf("Child has x = %d\n%d\n", ++x,++x);   // Since function arguments are evaluated before the function executes, both ++x expressions modify x before printf prints them. , print 3
    else
        printf("Parent has x = %d\n", --x); 
} 
int main() 
{ 
    forkexample(); 
    return 0; 
} 
