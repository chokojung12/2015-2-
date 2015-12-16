#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>


#define BUFSIZE 512



int main(){
	
	char buffer[BUFSIZE];
	int total = 0;
	ssize_t nread;
	ssize_t nwrite;
	int afile;
	int bfile;
	char original_file[] = "afile";
	char copy_file[] = "bfile";

	if((afile = open(original_file, O_RDONLY)) == -1){
		printf("afile open fail\n");
		exit(1);
	}
	else{	
		if((bfile = open(copy_file, O_WRONLY)) == -1){
			printf("bfile open fail\n");
			close(afile);
			exit(1);
		}
		while((nread = read(afile, buffer, BUFSIZE)) > 0){
			total += (int)nread;
			write(bfile, buffer, strlen(buffer));
			
		}
		close(afile);
		close(bfile);
		
	}
	printf("%d", total);
	return 0;
} 
