#include <stdio.h>
#include <unistd.h>

main(){
	printf("executing ls \n");
	execl("/bin/ls", "ls", "-l", (char *)0);
	perror("execl failed to run ls\n");
	exit(1);
}
