#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

int score = 0;

void end_game() {
    printf("\nFinal score: %i\n", score);
    exit(0);
}

int catch_signal(int sig, void (*handler)(int)) {
    struct sigaction action;
    action.sa_handler = handler;
    sigemptyset(&action.sa_mask);
    action.sa_flags = 0;

    int sigactionReturn = sigaction(sig, &action, NULL);

    if (sigactionReturn == -1)
    {
        perror("sigaction");
        exit(EXIT_FAILURE);
    }

    return sigactionReturn;
}

void times_up() {
    printf("\nTIME'S UP\n");
    raise(SIGINT);
}

void error(char *msg) {
    fprintf(stderr, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

int main() {

    catch_signal(SIGALRM, times_up);
    catch_signal(SIGINT, end_game);

    srand(time(0));

    while(1)
    {
        int a = rand() % 11;
        int b = rand() % 11;

        char txt[4];

        printf("\nWhat is %d times %d: ", a, b);
        alarm(5);
        fgets(txt, 5, stdin);
        // alarm(0);   // redundancy because when alarm() called any previously set alarm() is canceled

        int answer = atoi(txt);

        if(answer == a * b)
            score++;
        else
            printf("\nWrong! Score: %i\n", score);
    }

    return 0;
}