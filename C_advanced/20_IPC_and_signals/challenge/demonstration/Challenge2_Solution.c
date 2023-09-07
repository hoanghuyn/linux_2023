#include <unistd.h>
#include <sys/types.h>
#include <stdio.h> 
#include <string.h>

#define BUF_SIZE 100

int main() 
{
    char buf[BUF_SIZE];
    
    // Creating first child 
    pid_t n1 = fork(); 
  
    // Creating second child. First child also executes this line and creates grandchild.
    pid_t n2 = fork();

    if (n1 > 0 && n2 > 0)               // Parent block
    {
        sprintf(buf, "\nparent\n%d %d \nmy id is %d \nmy parentid is %d \n", n1, n2, getpid(), getppid());
        write(1, buf, strlen(buf));
    } 
    else if (n1 == 0 && n2 > 0)         // First child block
    { 
        sprintf(buf, "\nfirst child\n%d %d \nmy id is %d \nmy parentid is %d \n", n1, n2, getpid(), getppid());
        write(1, buf, strlen(buf));
    } 
    else if (n1 > 0 && n2 == 0)         // Second child block
    {
        sprintf(buf, "\nsecond child\n%d %d \nmy id is %d \nmy parentid is %d \n", n1, n2, getpid(), getppid());
        write(1, buf, strlen(buf));
    }
    else // if (n1 == 0 && n2 == 0)
    {                                   // Third child block - grandchild of parent, child of first child
        sprintf(buf, "\nthird child\n%d %d \nmy id is %d \nmy parentid is %d \n", n1, n2, getpid(), getppid());
        write(1, buf, strlen(buf));
    } 
  
    return 0; 
}