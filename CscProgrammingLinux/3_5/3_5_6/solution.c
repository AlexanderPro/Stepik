#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

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
    int pid = getpid();
    printf("%d\n", pid);
    daemon(0, 0);
    pause();
    return 0;
}