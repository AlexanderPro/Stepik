#include <stdio.h>
#include <stdlib.h>

int getppid(int pid)
{
    FILE* fp;
    int ppid;
    char fileName[512];
    sprintf(fileName, "/proc/%d/stat", pid);
    fp = fopen(fileName, "r");
    if (fp == NULL)
    {
        return 0;
    }
    fscanf(fp, "%*d %*s %*c %d", &ppid);
    fclose(fp);
    return ppid;
}

int main(int argc, char **argv)
{
    int pid = atoi(argv[1]);
    do
    {
     printf("%d\n", pid);
     pid = getppid(pid);
    } while (pid > 0);
    return 0;
}