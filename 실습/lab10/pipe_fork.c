#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 14

int main(){	
	int pipe_fd[2];  //0 read, 1 write
	int return_pipe;
	int status;
	char buffer[SIZE];
	char message[] = "Hello World!!";
	return_pipe = pipe(pipe_fd);
	pid_t pid = fork();
	
	if(return_pipe == 0){
		//child
		if(pid == 0){
			close(pipe_fd[1]);
			read(pipe_fd[0],buffer, SIZE);
			printf("child:%s\n",buffer);
			close(pipe_fd[0]);
		}
		//parent
		else{
			close(pipe_fd[0]);
			write(pipe_fd[1], "Hello World!!", SIZE);
			printf("parent:message sent\n");
			close(pipe_fd[1]);
		}
	}
	else{	
		printf("pipe failed\n");
		exit(0);
	}
	if((long)getpid() != 0){
		wait(&status);	
	}
	
	return 0;
}
