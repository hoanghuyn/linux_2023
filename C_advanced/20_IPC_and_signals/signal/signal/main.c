#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

void handler_divided_by_zero(int signum);

int main()
{
    int result;
    int v1, v2;
    void (*sigHandlerReturn)(int);

    sigHandlerReturn = signal(SIGFPE, handler_divided_by_zero);

    if (sigHandlerReturn == SIG_ERR) {    
        perror("Error in setting signal handler\n");
        return 1;
    }

    v1 = 121;
    v2 = 0;
    result = v1/v2;
    printf("Result of Divide by Zero is %d\n", result);

    return 0;
}

void handler_divided_by_zero(int signum)
{
    if (signum == SIGFPE)
    {
        printf("Received SIGFPE, Divide by Zero Exception\n");
        exit(0);
    }
    else printf("Received %d signal\n", signum);

    return;
}