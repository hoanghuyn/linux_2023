#include <stdio.h>
#include <signal.h>
#include <unistd.h>

void alarmHandler()
{
    printf("Alarm received\n");
}

int main()
{
    alarm(5);

    // NEED TO CATCH SIGALRM or process terminates
    signal(SIGALRM, alarmHandler);

    for(int i = 1; i < 10; i++)
    {
        printf("i = %d\n", i);
        sleep(1);
    }

    while(1);

    return 0;
}