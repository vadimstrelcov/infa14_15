#include <unistd.h>
int main() {
	symlink("file.txt", "file2.txt");
	return 0;
}
