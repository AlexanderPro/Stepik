#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
    char command[512];
    sprintf(command, "%s %s", argv[1], argv[2]);
    FILE * fp = popen(command, "r");
    int number = 0;
    if (fp == NULL)
    {
        return 1;
    }
    
    do
    {
        char ch = fgetc(fp);
        if (feof(fp))
        {
            break;
        }

        if (ch == '0')
        {
            number ++;
        }
    } while (1);

    printf("%d\n", number);
    return 0;
}