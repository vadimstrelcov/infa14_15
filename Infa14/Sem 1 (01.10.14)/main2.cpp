#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
int main() {
    int fd[2];
    pipe(fd);
    pid_t f=fork();
    if (f==-1) {
        printf("error\n");
    } else {
        if (f==0) { //child
            write(fd[1],"Hello world",12);
        } else {
            char s[12];
            read(fd[0],s,12);
            printf("%s",s);
        }
    }
    return 0;
}
