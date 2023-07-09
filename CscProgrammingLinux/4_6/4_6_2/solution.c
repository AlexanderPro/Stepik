#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <unistd.h>
#include <fcntl.h>

int number = 0;

int add_to_number(int f)
{
  char buffer[100 + 1];
  int bytes = read(f, buffer, 100);
  if (bytes > 0)
  {
      buffer[bytes] = 0;
      number += atoi(buffer);
  }
  return bytes;
}

int main()
{
    int f1 = open ("./in1", O_RDONLY);
    int f2 = open ("./in2", O_RDONLY);

    if (f1 == -1 || f2 == -1) 
    {
        return 1;
    }

    fd_set read_set;
    int f1_closed = 0;
    int f2_closed = 0;
    
    struct timeval tv;
    tv.tv_sec = 5;
    tv.tv_usec = 0;

    while (1)
    {
        FD_ZERO(&read_set);
        if (f1_closed == 0)
        {
            FD_SET(f1, &read_set);
        }

        if (f2_closed == 0)
        {
            FD_SET(f2, &read_set);   
        }

        int f = f1 > f2 ? f1 : f2;
        int result = select(f+1, &read_set, NULL, NULL, &tv);
        if (result != -1 && (f1_closed == 0 || f2_closed == 0))
        {
            if (FD_ISSET(f1, &read_set))
            {
                int number_result = add_to_number(f1);
                if (number_result == 0)
                {
                    f1_closed = 1;
                }
            }
      
            if (FD_ISSET(f2, &read_set))
            {
                int number_result = add_to_number(f2);
                if (number_result == 0)
                {
                    f2_closed = 1;
                }
            }

            if (f1_closed == 1 && f2_closed == 1)
            {
                break;
            }
        }
        else
        {
            break;
        }
    }

    close(f1);
    close(f2);	
    printf("%d\n", number);
    return 0;
}