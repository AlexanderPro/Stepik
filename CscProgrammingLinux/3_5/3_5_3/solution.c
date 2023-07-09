#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    FILE* fp;
    struct dirent **nameList;
    char fileName[512], foundProcessName[512];
    int processNumber = 0;

    int n = scandir("/proc", &nameList, NULL, alphasort);
    if (n < 0)
    {
        return 1;
    }

    while (n--)
    {
        sprintf(fileName, "/proc/%s/stat", nameList[n]->d_name);
        fp = fopen(fileName, "r");
        if (fp != NULL)
        {
            fscanf(fp, "%*d %s", foundProcessName);
            if (strstr(foundProcessName, "genenv") != NULL)
            {
                processNumber ++;
            }
            free(nameList[n]);
            fclose(fp);
        }
    }
    free(nameList);
    printf("%d\n", processNumber);
    return 0;
}