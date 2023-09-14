#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
    int sz, seek_pos = 0;
    char buf[] = "Mohan";

    int fd = open("input.txt", O_RDWR);
    if(fd < 0)
    {
        perror("Error occured during open");
        exit(1);
    }

    seek_pos = lseek(fd, -strlen(buf), SEEK_END);

    sz = write(fd, buf, strlen(buf));

    if(sz < 0)
    {
        perror("Error occured during write");
        exit(1);
    }

    close(fd);

    return 0;
}