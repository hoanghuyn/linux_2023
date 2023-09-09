/* Demo to show SIGUSR signal between child-parent process*/

#include <stdio.h> 
#include <stdlib.h> 
#include <sys/wait.h>
#include <unistd.h> 
  
static void sigint_handler(int signo)
{
    if (signo == SIGINT) {
        printf ("Ctrl + C pressed!\n");
        exit(0);
    }
}

static void child_sig_handler (int signo)
{
    if (signo == SIGUSR1)
        printf("SIGUSR1 caught from CHILD!\n");
    if (signo == SIGUSR2)
        printf("SIGUSR2 caught from CHILD!\n");
}

static void parent_sig_handler (int signo)
{
    if (signo == SIGUSR1)
        printf("SIGUSR1 caught from PARENT!\n");
    if (signo == SIGUSR2)
        printf("SIGUSR2 caught from PARENT!\n");
}

int main() 
{ 
    pid_t cpid; 

    if (signal(SIGINT, sigint_handler) == SIG_ERR)
    {
        fprintf(stderr, "Cannot handle SIGUSR1!\n");
        exit(-1);
    }

    sleep(5);

    cpid = fork();

    if(cpid == -1)
        exit(-1);           /* terminate */

    if(cpid == 0) {
        if (signal (SIGUSR2, child_sig_handler) == SIG_ERR) {
            fprintf (stderr, "Cannot handle SIGUSR2!\n");
            exit (-1);
        }

        sleep(2);

        printf("\nChild process sending SIGUSR1 to parent\n");
        kill(getppid(), SIGUSR1);
        sleep(1);
        sleep(5);
    } 
    else {   
        if (signal (SIGUSR1, parent_sig_handler) == SIG_ERR) {
            fprintf (stderr, "Cannot handle SIGUSR1!\n");
            exit (-1);
        }

        sleep(5);
        sleep(5);

        printf("\nParent process sending SIGUSR2 to child\n");
        kill(cpid, SIGUSR2);
    }
  
    return 0; 
} 
