#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

#define FIFO "myfifo"

int main()
{
    int fd;
    char msg[100];

    printf("Enter Message: ");
    fgets(msg, sizeof(msg), stdin);

    fd = open(FIFO, O_WRONLY);

    write(fd, msg, strlen(msg));

    close(fd);

    return 0;
}
