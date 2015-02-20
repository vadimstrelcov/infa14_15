#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <stdio.h>
int main() {
	int a=open("1.txt",O_WRONLY);
	char s[100];
	gets(s);
	write(a,s,strlen(s)+1);
	return 0;
}
