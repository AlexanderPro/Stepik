#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <netinet/ip.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define BUF_SIZE 5000

int comp (const void * elem1, const void * elem2)
{
    char f = *((char*)elem1);
    char s = *((char*)elem2);
    if (f < s) return 1;
    if (f > s) return -1;
    return 0;
}

int main(int argc, char **argv)
{
    struct sockaddr_in local;
    local.sin_addr.s_addr = htonl(INADDR_LOOPBACK);
    local.sin_port = htons(atoi(argv[1]));
    local.sin_family = AF_INET;

    int s = socket(AF_INET, SOCK_STREAM, 0);
    int result = bind(s, (struct sockaddr*) &local, sizeof(local));
    if (result != 0)
    {
        return 1;
    }

    listen(s, 5);
    int as = accept(s, NULL, NULL);
 
    char buffer[BUF_SIZE];
    int length = 0;
    while ((length = read(as, buffer, BUF_SIZE)) >= 0)
    {
        buffer[length] = 0;
        if (strncmp(buffer, "OFF\n", 4) == 0)
        {
            break;
        }
        else
        {
            qsort(buffer, strlen(buffer), 1, comp);
            write(as, buffer, strlen(buffer) + 1);
        }
    }

    close(s);
    close(as);
    return 0;
}