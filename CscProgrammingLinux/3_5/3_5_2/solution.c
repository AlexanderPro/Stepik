#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ppid;
    FILE* fp;
    fp = fopen("/proc/self/stat", "r");
    if (fp == NULL)
    {
        return 1;
    }
    fscanf(fp, "%*d %*s %*c %d", &ppid);
    printf("%d\n", ppid);
    fclose(fp);
    return 0;
}