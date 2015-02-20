#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
    int fd = open("input.txt",O_RDWR);
    printf("%d\n",fd);
    write(fd,"Hello_World!",13);
    close(fd);
    fd = open("input.txt",O_RDONLY);
    char s[20];
    read(fd,s,20);
    printf("%s",s);
    close(fd);
    return 0;
}
