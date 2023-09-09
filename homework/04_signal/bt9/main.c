/* Demo to show SIGUSR signal between child-parent process*/

#include <stdio.h> 
#include <stdlib.h> 
#include <sys/wait.h>
#include <unistd.h>

sigset_t sigset_all;

static void sigint_handler(int signo)
{
    if (signo == SIGINT) {
        printf ("SIGINT came!\n");
        exit(0);
    }
}

int main() 
{
    // Initialize signal filter
    sigemptyset(&sigset_all);

    int is_sigint_blocked = sigismember(&sigset_all, SIGINT);

    if (signal(SIGINT, sigint_handler) == SIG_ERR)
    {
        fprintf(stderr, "Cannot handle SIGINT!\n");
        exit(-1);
    }

    sleep(5);

    // Check whether SIGINT is blocked
    if (is_sigint_blocked)
    {
        // Tín hiệu SIGINT bị chặn
        printf("SIGINT Blocked!\n");
    } else
    {
        printf("SIGINT Unblocked!\n");
    }

    printf("Blocking SIGINT...\n");
    
    // Add SIGINT into signal filter
    sigaddset(&sigset_all, SIGINT);

    // Block SIGINT
    sigprocmask(SIG_BLOCK, &sigset_all, NULL);

    printf("SIGINT Blocked!\n");

    sleep(5);

    printf("Unblocking SIGINT...\n");
    // Unblock tín hiệu SIGINT
    sigprocmask(SIG_UNBLOCK, &sigset_all, NULL);
    printf("SIGINT Unblocked!\n");

    return 0; 
} 
