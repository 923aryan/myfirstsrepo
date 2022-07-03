#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main()
{
    int fd[2];
    int pipeId = pipe(fd);
    if (pipeId == -1)
    {
        printf("Error creating the pipe.\n");
    }

    pid_t pid = fork();
    if (pid == 0)
    {
        close(fd[0]);
        printf("Inside the Child.\n");
        printf("Writing the file.\n");
        char buff[20] = {"Hello There!"};
        write(fd[1], &buff, sizeof(buff));
        close(fd[1]);
    }
    else
    {

        close(fd[1]);
        char bf[20];
        read(fd[0], &bf, sizeof(bf));
        printf("Reading the file.\n");
        printf("Got message from the child: %s\n", bf);
    }

    return 0;
}