#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

void main(void)
{
    pid_t cpid;

    cpid = fork();

    if (cpid < 0) {
        printf("Error: fork() failed\n");
        exit(1);
    } 
    else if (cpid == 0) {
        printf("\n  I'm the child process\n");
        printf("    My PID is: %d\n", getpid());
        printf("    My parent PID is: %d\n", getppid());
    } else
    {
        printf("\nIm the parent process\n");
        printf("My PID is: %d\n", getpid());
        sleep(1);   // avoid child become orphane process
    }
}