#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <string.h>


int main(int argc, char *argv[]){
	pid_t cid1, cid2;
	int stat_val;
	char *child_num;

	cid1 = fork(); 

	if(cid1 = 1){
		cid2 = fork();
	}
	// parent
	if(cid1 && cid2){
		printf("Parent: waiting for childeren\n");
		
		int count = 0;
		while( count < 2 ){
			child_num = (wait(&stat_val) == cid1)?"first":"second";
			printf("Parent : %s Child: %d\n", child_num, WEXITSTAUS(stat_val));
			++count;
		}

		printf("Parent : All Children terminated\n");
		
	}
	//child
	else{
		child_num = !cid!?"1":"2";
		execl("hello",child_num ,null);
	}
	return 0;
}
