#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/shm.h>

int main(int argc, char **argv)
{
    int key1 = atoi(argv[1]);
    int key2 = atoi(argv[2]);
    int key3 = ftok("/", 0);
    int shmid1 = shmget((key_t)key1, 1000, 0600);
    int* shared_memory1 = (int*)shmat(shmid1, NULL, 0);
    int shmid2 = shmget((key_t)key2, 1000, 0600);
    int* shared_memory2 = (int*)shmat(shmid2, NULL, 0);
    int shmid3 = shmget((key_t)key3, 1000, IPC_CREAT | 0666);
    int* shared_memory3 = shmat(shmid3, (void *)0, 0);
    int i;
    for (i = 0; i < 100; i++)
    {
        shared_memory3[i]= shared_memory1[i] + shared_memory2[i];
    }
    printf("%d\n", key3);
    shmdt(shared_memory1);
    shmdt(shared_memory2);
    shmdt(shared_memory3);
    return 0;
}