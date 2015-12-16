#include <unistd.h>
#include <error.h>
#include <stdio.h>

int main(int argc, char *argv[]){
	if(argc != 3){
		perror("argc error\n");
	}
	else{
		if(link(argv[1], argv[2]) == 0){
			if(unlink(argv[1])==0){
				printf("sucess\n");
			}
			else{
				printf("unlink failed");
			}
		}
		else{
			printf("link error\n");
		}
	}
	return 0;
}
