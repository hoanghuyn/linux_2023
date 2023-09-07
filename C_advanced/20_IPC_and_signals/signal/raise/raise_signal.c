#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

int main()
{    
    printf("Testing SIGSTOP\n");
    raise(SIGSTOP);
    printf("I'm back\n\n"); 

    return 0;
}