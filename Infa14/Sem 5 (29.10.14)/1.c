#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <string.h>

//msgsnd(id, message, size, 0);
//msgrcv(id,&msgbuf,size,type(1,..,inf) (0 - all types), 0)

typedef struct msgbuf {
	long mtype;
	char str[14];
} msgbuf;

int main() {

    int fl=0;
    key_t a=ftok("file.txt",0);
    int msg_id=msgget(a, IPC_CREAT | 0666);

    struct msgbuf A;
    strcpy(A.str,"Hello, world!");
    A.mtype=1;

    msgsnd(msg_id, &A, sizeof(A)-sizeof(long), 0);

    return 0;
}
