#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#define TOTALFORK 3 //총 생성해야할 프로세스 수

int main() {
	pid_t pids[TOTALFORK], pid;
	int runProcess = 0; //생성한 프로세스 수
	int i;	

	for(i = 0; i < TOTALFORK; ++i){
		pids[i] = fork();	
		if(pids[i] == 0){
			printf("create %ld process\n", (long)getpid());
		}
	}
	
	

	
	return 0;	
}
