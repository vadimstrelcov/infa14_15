#include <sys/types.h>
#include <dirent.h>
#include <stdio.h>
#include <string.h>

int i,j;

void print(char *str, int depth) {
	DIR *D=opendir(str);
	for (i=0;i<5;i++) {
		struct dirent *DD;
		DD=readdir(D);
		for (j=0;j<depth;j++) printf(" ");
		printf("d_name = %s | d_type = %d\n",DD->d_name, DD->d_type);
		if (DD->d_type==4 && DD->d_name[0]!='.') {	
			char str2[100]="";
			strcat(str2,str);
			if (depth!=0) {
				strcat(str2,"/");
			}
			strcat(str2,DD->d_name);
			printf("%s\n",str2);
			print(str2,depth+1);
		}
	}
	closedir(D);
}

int main(int argc, char **argv) {
	print(argv[1],0);
	return 0;
}
