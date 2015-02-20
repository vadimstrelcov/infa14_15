#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
int main(int argc, char **argv) {
	struct stat a;
	printf("%d\n",stat(argv[1], &a));
	printf("ID device=%d\ninode number=%d\nprotection=%d\nnumber of hard links=%d\nuser ID ownew=%d\ngroup ID owner=%d\ndevice ID owner=%d\ntotal size=%d\nblocksize for file system IO=%d\nnumber of 512 B blocks allocated=%d\ntime of last access=%d\ntime of last modif=%d\ntime of last status change=%d\n",a.st_dev,
	a.st_ino,
	a.st_mode,
	a.st_nlink,
	a.st_uid,
	a.st_gid,
	a.st_rdev,
	a.st_size,
	a.st_blksize,
	a.st_blocks,
	a.st_atime,
	a.st_mtime,
	a.st_ctime);
	return 0;
}
