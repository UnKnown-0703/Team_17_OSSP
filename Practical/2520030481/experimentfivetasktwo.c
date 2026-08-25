#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
    int fd[2];
    pid_t pid;

    pipe(fd);

    pid = fork();

    if (pid < 0)
    {
        perror("fork");
        return 1;
    }

    if (pid == 0)
    {
        // Child: execute ls -l
        close(fd[0]);

        dup2(fd[1], STDOUT_FILENO);
        close(fd[1]);

        execl("/bin/ls", "ls", "-l", (char *)NULL);

        perror("execl");
        exit(1);
    }
    else
    {
        // Parent: execute grep ".c"
        close(fd[1]);

        dup2(fd[0], STDIN_FILENO);
        close(fd[0]);

        execl("/bin/grep", "grep", ".c", (char *)NULL);

        perror("execl");
        exit(1);
    }

    return 0;
}
