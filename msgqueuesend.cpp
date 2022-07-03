#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <stdlib.h>
#include <sys/ipc.h>
using namespace std;
#define MAX 512

struct message_queue
{
    int msg_type;
    char msg_text[MAX];
};

int main()
{
    char buff[100];
    int msgid;
    msgid = msgget(key_t(2345), 0666 | IPC_CREAT);
    struct message_queue msg;
    read(0, &buff, MAX);
    strcpy(msg.msg_text, buff);
    msg.msg_type = 1;
    if (msgsnd(msgid, &msg, sizeof(msg), 0) == -1)
    {
        cout << "Message not sent!\n";
    }
    else
    {
        cout << "Message sent!\n";
    }

    return 0;
}