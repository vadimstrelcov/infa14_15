#include <stdio.h>
#include <sys/sem.h>
#include <sys/ipc.h>
#include <sys/types.h>

int main() {

    key_t a=ftok("file.txt",0);
    int sem_id=semget(a, 3,IPC_CREAT | 0666);

    while (1) {
	    struct sembuf A;
	    A.sem_op=+1;
	    A.sem_num=0;
	    A.sem_flg=0;
	    char s[2];
	    gets(s);
	    semop(sem_id,&A,1);
	    printf("i'm second program %d\n",sem_id);
    } 
    	
    return 0;
}
