#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>

int main(int argc, char **argv) {
	DIR* D=opendir(argv[1]);
	struct dirent *DD;
	int i;
	for (i=0;i<20;i++) {
		DD=readdir(D);
		printf("d_name = %s\n",DD->d_name);
	}	
	closedir(D);
	return 0;
}
