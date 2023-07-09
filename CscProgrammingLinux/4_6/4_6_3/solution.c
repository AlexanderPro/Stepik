#include <signal.h>
#include <stdio.h>
#include <unistd.h>

int numberSigusr1 = 0;
int numberSigusr2 = 0;
int numberSigterm = 0;

void numberSigusr1_handler(int signal)
{
    numberSigusr1 ++;
}

void numberSigusr2_handler(int signal)
{
    numberSigusr2 ++;
}

void numberSigterm_handler(int signal)
{
    numberSigterm ++;
}

int main()
{
    signal(SIGUSR1, numberSigusr1_handler);
    signal(SIGUSR2, numberSigusr2_handler);
    signal(SIGTERM, numberSigterm_handler);

    while(numberSigterm == 0)
    {
        usleep(1000);
    }

    printf("%d %d\n", numberSigusr1, numberSigusr2);
    return 0;
}