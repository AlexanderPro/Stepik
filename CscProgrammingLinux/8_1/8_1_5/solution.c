#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <string.h>

int main(int argc, char **argv)
{
    int optindex = 0;
    int optchar = 0;

    struct option opts[] =
    {
        {"query", required_argument, 0, 'q'},
        {"longinformationrequest", no_argument, 0, 'i'},
        {"version", no_argument, 0, 'v'},
    };

    char reschar = '+';
    while ((optchar = getopt_long(argc, argv, "ivq:", opts, &optindex)) != -1)
    {
        if (!((optchar == 'i' || optchar == 'v' || optchar == 'q') || (optchar == '\0' && optarg != NULL)))
        {
            reschar = '-';
        }
    }

    printf("%c\n", reschar);
    return 0;
}