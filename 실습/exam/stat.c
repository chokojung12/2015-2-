#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>
#include <stdlib.h>
#include <unistd.h>




int main(){
	struct stat file_info;
	int state;
	
	
	if((state = stat("stat.c", &file_info)) == -1){
		perror("error");	
	}
	
	else{
		printf("file: %d\n", file_info.st_ino);
		printf("file: %d\n", file_info.st_uid);
		printf("file: %d\n", file_info.st_mtime);
	}
	return 0;
}
