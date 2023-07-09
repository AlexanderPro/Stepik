#include <signal.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

int numberSigurg = 0;

void numberSigurg_handler(int signal)
{
    numberSigurg ++;
}

int getpid()
{
    FILE* fp;
    int pid;
    fp = fopen("/proc/self/stat", "r");
    if (fp == NULL)
    {
        return 0;
    }
    fscanf(fp, "%d", &pid);
    fclose(fp);
    return pid;
}

int main()
{
    signal(SIGURG, numberSigurg_handler);
    int pid = getpid();
    printf("%d\n", pid);
    daemon(0, 0);
    while(numberSigurg == 0)
    {
        usleep(1000);
    }

    return 0;
}