#include <stdio.h>	/* fork2.c */
#include <unistd.h>
#include <sys/types.h>

int main(void) {
	pid_t childpid;

	childpid = fork();
	if (childpid == -1){
		printf("Failed to fork");
		return 1;
	}
	if (childpid == 0)
		printf("I am child %ld\n", (long)getpid());
	else
		printf("I am parent %ld\n", (long)getpid());
	return 0;
}
