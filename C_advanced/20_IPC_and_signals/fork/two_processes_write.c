#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_COUNT   50
#define BUF_SIZE    100

void main(void)
{
    pid_t pid;
    char buf[BUF_SIZE];

    fork();
    pid = getpid();

    for (int i = 1; i <= MAX_COUNT; i++) {
        sprintf(buf, "This line is from pid %d, value = %d\n", pid, i);
        write(1, buf, strlen(buf));
        // printf("This line is from pid %d, value = %d\n", pid, i);
    }
}