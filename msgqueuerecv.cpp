#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/msg.h>
using namespace std;
#define MAX 512
struct message_queue
{
    int msg_type;
    char msg_text[MAX];
};
int main()
{
    int msgid = msgget(key_t(2345), 0666);
    struct message_queue msg;
    msgrcv(msgid, &msg, sizeof(msg), 0, 0);
    cout << msg.msg_type << "\n"
         << msg.msg_text << endl;
    return 0;
}