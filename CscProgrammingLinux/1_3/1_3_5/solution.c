#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>
#include <dlfcn.h>

int (*foo)(int);

int main(int argc, char **argv)
{
    void *hdl = dlopen(argv[1], RTLD_LAZY);
    if (hdl == NULL)
        return 1;
    
    foo = (int(*)(int))dlsym(hdl, argv[2]);
    if (foo == NULL)
        return 2;
    
    int result = foo(atoi(argv[3]));
    printf("%d\n", result);
    
    return 0;
}