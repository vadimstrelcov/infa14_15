#include <sys/msg.h>
#include <sys/ipc.h>
#include <string.h>
#include <stdio.h>
typedef struct msg {	
  long type;
} msg;
int V(int msg_id, void *a) {
  msgsnd(msg_id, a, 0, 0);
}
int P(int msg_id, void *a) {
	msgrcv(msg_id, a, 0, 0, 0);
}
int Z(int msg_id, void *a) {
	
}
int main() {
	msg a;
	key_t key=ftok("file.txt", 0);
	int msg_id=msgget(key, IPC_CREAT | 0666);
	
	return 0;
}
