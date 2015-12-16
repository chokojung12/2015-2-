#include <stdio.h>
#include <stdlib.h>
#include <wait.h>
#define TOTALFORK 10 //총 생성해야할 프로세스 수

int main() {
	pid_t pids[TOTALFORK], pid, pid_state;
	int runProcess = 0; //생성한 프로세스 수
	
	
	while(runProcess < TOTALFORK) {
		pids[runProcess] = fork();//fork 생성	
			
		if(pids[runProcess] < 0){
			return -1;
		} 
		else if(pids[runProcess] == 0){//자식 프로세스
			printf("child  %ld create\n", (long)getpid());
			sleep(3);
			if(runProcess >= 1){
				pid_state = waitpid(pids[runProcess-1], NULL ,1);
				if(pid_state != 0 && pid_state != 1){
					printf("child %ld exit\n",(long)getpid());
					exit(0);
				}
			}
			else{
				printf("child %ld exit\n",(long)getpid());
				exit(0);
			}
		} 
		else { //부모 프로세스
			printf("parent %ld\n", (long)getpid());	
			waitpid(-1,NULL ,1);
		}	
		runProcess++;
	}	
	return 0;
}
