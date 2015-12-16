#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>



int main(){
	int return_stat;
	struct stat buf;
	return_stat = stat("test.txt", &buf);
	printf("%d\n", buf.st_ino);
	return 0;
}
