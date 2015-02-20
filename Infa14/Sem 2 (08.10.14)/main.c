#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main() {
    mknod("1.txt",S_IFIFO | 0666, 0);
    return 0;
}
