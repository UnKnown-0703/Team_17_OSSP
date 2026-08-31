#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>

#define FIFO "myfifo"

int main()
{
    char buffer[1024];

    mkfifo(FIFO, 0666);

    printf("Server Started...\n");

    while(1)
    {
        int fd = open(FIFO, O_RDONLY);

        int n = read(fd, buffer, sizeof(buffer)-1);

        if(n > 0)
        {
            buffer[n] = '\0';
            printf("Message from Client: %s\n", buffer);
        }

        close(fd);
    }

    return 0;
}
	
