#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int main() {
	int a=open("1.txt",O_RDONLY);
	char s[100];	
	read(a,s,13);
	printf("%s",s);	
	return 0;
}
