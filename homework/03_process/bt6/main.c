#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

void main(void)
{
    pid_t cpid;
    int status;

    cpid = fork();

    if (cpid < 0)
    {
        printf("Error: fork() failed\n");
        exit(1);
    }
    else if (cpid == 0)
    {
        printf("\nchild executing first its pid = (%d)\n", getpid());
        sleep(10);
        printf("Child process exiting...\n");
        exit(1);
    }
    else // (cpid > 0)
    {
        printf("\n Parent executing before wait()\n");

        cpid = wait(&status);

        printf("\n wait() in parent done\nParent pid = %d\n", getpid());
        printf("\n cpid returned is (%d)\n", cpid);
        printf("\n exit status is (%d)\n", status);
    }
}

#if 0
Process termination status (int) 16 bit number
1. status value if  child process has normal exit/termination
   15......8    |     7......0
   XXXXXXXX     |     XXXXXXXX 
   exitStaus    |     0


2. killed by signal
    15......8    |     7   ......0
    unused       |     X   termination signal
                       |
                       |-----> core dump flag
#endif