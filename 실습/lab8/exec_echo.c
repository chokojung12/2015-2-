#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <error.h>


#define CHILD_COUNT 2

int main(){
	pid_t pid[CHILD_COUNT];
	int run_process = 0;
	char *echo_message1 = "This is Child1";
	char *echo_message2 = "This is Child2";
	int *status;	
	
	while(run_process < CHILD_COUNT){
		pid[run_process] = fork();

		if(pid[run_process] == -1){
			printf("fork failed\n");
			exit(1);
		}
		else if(pid[run_process] == 0){
			if(run_process == 0){
				printf("create child process : %ld\n", (long)getpid());
				execl("/bin/echo", "echo", echo_message1, (char *)0);
				perror("execl failed\n");
				exit(1);
			}
			else if(run_process == 1){
				printf("create child process : %ld\n", (long)getpid());
				execl("/bin/echo", "echo", echo_message2, (char *)0);
				perror("execl failed\n");
				exit(1);
			}
		}
		else{
			printf("Parent process : %ld\n", (long)getpid());
			printf("Parent : Waiting Children\n");
			wait(status);
		}
		++run_process;
	}
		
	if((long)getpid() != 0){
		printf("Parent : All Children terminated\n");
	}
	return 0;
}
