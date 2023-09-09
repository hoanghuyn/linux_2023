/*
Demonstrate avoid Zombie process by using SIGCHLD signal

Note: If a process is in Zombie state, this means a entry of that process is still present in process table
*/

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

void sig_handler(int signo)
{
    if (signo == SIGCHLD)
    {
        printf("\nSIGCHLD signal received\n");
        waitpid(-1, NULL, WNOHANG);
    }
}

int main()
{
    pid_t id;
    printf("Parent Process : Executed by parent process before fork() - PID = (%d)\n", getpid());

    if (signal(SIGCHLD, sig_handler) == SIG_ERR)
    {
        fprintf(stderr, "Cannot handle SIGCHLD!\n");
        exit(-1);
    }

    id = fork(); // from this point of code, the child and parent process both execute
    
    if (id < 0)
    {
        printf("\nfork failed\n");
        exit(-1);
    }
    if (id > 0)
    { /* Parent process*/
        printf("\nParent Process: I have created child process with PID = (%d)\n", id);
        while(1);
    } 
    else
    { /* Child process*/
        printf("Child process excuting...\n");
        sleep(5);
        printf("Child process exiting...\n");
        exit(0);
    }

    return 0;
}