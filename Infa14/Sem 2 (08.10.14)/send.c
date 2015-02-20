#include <fcntl.h>
#include <stdio.h>
int main()
{
	int a, n;
	char b[100];
	a=open("/home-local/student/alalo.fifo", O_RDONLY);
	while(b[0]!='0')
	{
		read(a, b, 1);
		n=b[0];
		read(a, b, n+1);
		printf("%s\n", b);
	}
	close(a);
	return 0;
}
