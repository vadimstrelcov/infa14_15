#include <stdio.h>
#include <sys/ipc.h>
#include <sys/types.h>
#include <sys/msg.h>
#include <errno.h>

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
	
    struct msgbuf B;
    while (1) {
        msgrcv(msg_id, &B, sizeof(B)-sizeof(long), 0, 0);
        printf("%s\n",B.str);
        if (B.mtype==255) {
             break;
        }
    }
    return 0;
}
