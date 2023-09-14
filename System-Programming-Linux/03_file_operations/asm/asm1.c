/* Program to write to a existing file in O_APPEND mode and  O_TRUNC mode*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <malloc.h>
#include <unistd.h>

int main()
{
    int sz;
    char buf[100];

    strcpy(buf, "Display content in screen using system call write() program!\n");

    sz = write(1, buf, strlen(buf));

    if(sz < 0)
    {
        perror("Error occured during write");
        exit(1);
    }

    return 0;
}