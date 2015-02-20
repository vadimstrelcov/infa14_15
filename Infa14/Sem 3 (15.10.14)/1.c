#include <sys/types.h>
#include <sys/stat.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <fcntl.h>
#include <stdio.h>
#include <errno.h>

int main() {
    int i=-1;
    key_t k=ftok("file.txt",0);
    int shm_id=shmget(k,3*sizeof(int),0666 | IPC_CREAT | IPC_EXCL);
    if (shm_id==-1) {
	if (errno==EEXIST) {
            shm_id=shmget(k,3*sizeof(int),0);
	}
        i=1;
    }
    int *q=shmat(shm_id,NULL,0);
    if (i==-1) {
	for (i=0;i<3;i++) {
            q[i]=0;
        }
    }
    q[0]++;
    q[2]++;
    printf("%d %d %d\n", q[0], q[1], q[2]);  
    shmdt(NULL);  
    return 0;
}
