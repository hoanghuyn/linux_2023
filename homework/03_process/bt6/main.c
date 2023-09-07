#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

void main(void)
{
    pid_t pid;

    pid = fork();

    if (pid >= 0) {
        if (pid == 0) {
            printf("\nI'm the child process\n");
            printf("My PID is: %d\n", getpid());
            printf("My parent PID is: %d\n", getppid());
        } else {
            printf("\nIm the parent process\n");
            printf("My PID is: %d\n", getpid());
        }
    } else {
        printf("fork() failed!\n");
    }    
}