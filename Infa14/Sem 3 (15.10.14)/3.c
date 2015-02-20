#include <pthread.h>
#include <stdio.h>

int a;
pthread_t pthread1, pthread2;

void *main2(void* arg) { //new thread
    a++;
    printf("pthread_id2=%u a=%d\n",pthread_self(),a);
}

int main() {
    a=0;

    pthread1=pthread_self();
    int pthread_id2=pthread_create(&pthread2,NULL,main2,NULL);

    a++;
    printf("pthread_id1=%u a=%d\n", pthread1,a);

    pthread_join(pthread2,NULL);
    printf("result: a=%d\n",a);
    return 0;
}
