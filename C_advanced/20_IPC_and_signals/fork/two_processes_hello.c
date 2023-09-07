#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    // make two processes which run same program after this instruction
    fork();
    
    printf("Hello World\n");
    return 0;
}