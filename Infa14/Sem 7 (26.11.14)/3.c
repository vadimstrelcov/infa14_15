#include <sys/mman.h>
#include <sys/types.h>
#include <fcntl.h>
#include <stdio.h>

int main(int argc, char** argv) {
	int fd = open(argv[1], 0666 | O_RDWR);
	void *q = mmap(NULL, 27, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
	printf("%s",(char*)q);
	return 0;
}
