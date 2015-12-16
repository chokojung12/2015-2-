#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main(){
	pid_t childpid;
	
	childpid = fork();

	if(childpid == -1 ){
		printf("Failed to fork\n");
		return 1;
	}
	else if( childpid == 0 ){
		printf("i am child %ld\n", (long)getpid());
	}
	else{
		printf("i'm parent %ld\n", (long)getpid());
	}
	return 0;
}
