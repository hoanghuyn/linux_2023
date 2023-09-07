#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <time.h>

void signalHandler(int signal_value);

int main()
{
    int i;  /* counter used to loop 100 times */
    int x;  /* variable to hold random  values between 1-50 */

    signal(SIGINT, signalHandler);  /* register signal handler */
    srand( clock() );                 /* seed random number generator */

    /* Output numbers 1 to 100 */
    for(int i = 1; i <= 100; i++) {
        x = 1 + rand() % 50;  /* generate random number to raise SIGINT  */
        /* raise SIGINT when x is 25 */
        if (x == 25) {
            raise(SIGINT);
        }

        printf("%4d", i);

        if (i % 10 == 0) {
            printf("\n");
        }
    }   /* end for */

    return 0;
}   /* end main */

void signalHandler(int signal_value) {
    int response; /* user's response to signal (1 or 2) */

    printf("%s%d%s\n%s", "\nInterrupt signal ( ", signal_value, \
        " ) received.", "Do you wish to continue ( 1 = yes or 2 = no )? ");
    scanf("%d", &response);

    /* check for invalid responses */
    while ( response != 1 && response != 2) {
        printf( "( 1 = yes or 2 = no)? ");
            scanf("%d", &response);
    }   /* end while */

    /* determine if it is time to exit */
    if ( response == 1) {
        /* register signal handler for next SIGINT */
        signal(SIGINT, signalHandler);
    } /* end if */
    else {
        exit(EXIT_SUCCESS);
    } /* end else */
}   /* end function signalHandler */