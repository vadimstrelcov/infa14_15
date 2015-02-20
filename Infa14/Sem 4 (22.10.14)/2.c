/*
P(S) while (S) block
     S--;
V(S) S++;


S=0
A(S,n) : s+=n
D(S,n) : while (S<n) block
	 s-=n;
Z(S) while (S!=0) block



struct sembuf {
sem_op;
sem_num;
sem_flg;
};

sem_op + -> A | - -> D | 0 -> Z
sem_num - number of semophore
sem_flg=0; useless for us

semop(sem_id, *sembuf, number_of_semaphores). number of sem = 0

*/


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
	    printf("i'm first program %d\n",sem_id);
    }    	
    return 0;
}
