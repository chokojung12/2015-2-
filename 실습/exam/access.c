#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>
#include <stdlib.h>
#include <unistd.h>




int main(int argc, char *argv[]){
	
	int state;
	

	if(argc != 2){
		perror("access failed");
	}
	else{
		state = access(argv[1], R_OK);
		if(state == 0){
			printf("read ok\n");
		}
	}
	return 0;
}
