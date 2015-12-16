#include <unistd.h>


int main(){
	char buf[200];
	symlink("symlink.c","sylink2.c");
	readlink("sylink2.c",buf, 200);
	printf("%s", buf);
	return 0;
}
