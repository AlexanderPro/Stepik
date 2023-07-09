#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int number = 0;

void calculateChildProcesses(int id)
{
    FILE* fp;
    struct dirent **nameList;
    char fileName[512];
    int pid, ppid;

    int n = scandir("/proc", &nameList, NULL, alphasort);
    if (n < 0)
    {
        return;
    }

    while (n--)
    {
        sprintf(fileName, "/proc/%s/stat", nameList[n]->d_name);
        fp = fopen(fileName, "r");
        if (fp != NULL)
        {
            fscanf(fp, "%d %*s %*c %d", &pid, &ppid);
            if (ppid == id)
            {
                number ++;
                calculateChildProcesses(pid);
            }
            free(nameList[n]);
            fclose(fp);
        }
    }
    free(nameList);
}

int main(int argc, char **argv)
{
    number ++;
    calculateChildProcesses(atoi(argv[1]));
    printf("%d\n", number);
    return 0;
}