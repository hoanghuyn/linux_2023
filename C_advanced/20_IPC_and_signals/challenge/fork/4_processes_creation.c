#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void fork_failed(void);

int main()
{
    pid_t pid;

    pid = fork();

    if (pid == 0)
    {
        // 1st child process
        printf("first child\n");
        printf("    my id is %d\n", getpid());
        printf("    my parent's id is %d\n\n", getppid());
    } else if (pid > 0)
    { 
        // parent process
        printf("parent\n");
        printf("    my id is %d\n", getpid());
        printf("    my parent's id is %d\n\n", getppid());

        pid = fork();
        if (pid == 0)
        {
            // 2nd child process
            printf("second child\n");
            printf("    my id is %d\n", getpid());
            printf("    my parent's id is %d\n\n", getppid());
        } else if (pid > 0)
        {
            // parent process
            pid = fork();

            if (pid == 0)
            {
                // 3rd child process
                printf("third child\n");
                printf("    my id is %d\n", getpid());
                printf("    my parent's id is %d\n\n", getppid());
            } else if (pid > 0)
            {
                // parent process
                int status;
                waitpid(pid, &status, 0);
            } else fork_failed();
        } else fork_failed();
    } else fork_failed();

    return 0;
}

void fork_failed(void) {
    // fork failed
    printf("fork() failed!\n");
    exit(1);
}