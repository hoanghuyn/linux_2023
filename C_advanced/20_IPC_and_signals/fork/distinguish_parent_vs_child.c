#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_COUNT   20
#define BUF_SIZE    100

void parent_process();
void child_process();

int main()
{
    pid_t pid;

    pid = fork();
    
    if(pid == 0)
        child_process();
    else if (pid > 0)
        parent_process();
    else {
        // fork failed
        printf("fork() failed!\n");
        return 1;
    }

    return 0;
}

void parent_process()
{
    int i = 0;
    for(i = 1; i <= MAX_COUNT; i++)
        printf("This line is from parent, value = %d\n", i);
    
    printf("*** Parent is done ***\n");
}

void child_process()
{
    int i = 0;
    for (i = 1; i <= MAX_COUNT; i++)
        printf("    This line is from child, value = %d\n", i);

    printf("    *** Child is done ***\n");
}