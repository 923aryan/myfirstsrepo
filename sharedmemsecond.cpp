#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/shm.h>
using namespace std;
int main()
{
    void *shared_mem;
    char buff[100];
    int shmid = shmget(key_t(2022), 1024, 0666);
    shared_mem = shmat(shmid, NULL, 0);
    cout << "Process Attached at process: " << shmid << endl;
    cout << (char *)shared_mem << endl;
    return 0;
}