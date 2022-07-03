#include <bits/stdc++.h>
#include <sys/shm.h>
#include <unistd.h>
using namespace std;
int main()
{
    void *shared_mem;
    char buff[100];
    int shmid;
    shmid = shmget(key_t(2022), 1024, 0666 | IPC_CREAT);
    shared_mem = shmat(shmid, NULL, 0);
    cout << "Process Attached at process: " << shmid << endl;
    read(0, &buff, 100);
    strcpy((char *)shared_mem, buff);
    printf("Wrote: %s\n", (char *)shared_mem);

    return 0;
}