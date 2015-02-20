#include <fcntl.h>
#include <string.h>
#include <stdio.h>
int main()
{
	int a, n;
	char b[100];
	a=open("/home-local/student/alalo.fifo",O_WRONLY);
	while(b[0]!='0')
	{
		scanf("%s",b);
		b[99]=(char)strlen(b);
		write(a, b+99, 1);
		write(a, b, b[99]+1);
	}
	write(a, "0", 2);
	close(a);
	return 0;
}
