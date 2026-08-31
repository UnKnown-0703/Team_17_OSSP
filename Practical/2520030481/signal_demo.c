#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

void sigint_handler(int sig)
{
    printf("\nSIGINT Received (Ctrl+C)\n");
}

void sigterm_handler(int sig)
{
    printf("\nSIGTERM Received\n");
    exit(0);
}

void sigusr1_handler(int sig)
{
    printf("\nSIGUSR1 Received\n");
}

int main()
{
    signal(SIGINT, sigint_handler);
    signal(SIGTERM, sigterm_handler);
    signal(SIGUSR1, sigusr1_handler);

    printf("Process ID: %d\n", getpid());
    printf("Waiting for Signals...\n");

    while(1)
    {
        pause();
    }

    return 0;
}
