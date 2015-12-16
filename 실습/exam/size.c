#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <error.h>
#include <stdlib.h>
#include <unistd.h>




int main(){
	int read_fd;
	char read_filename[] = "afile";
	off_t file_size;

	if((read_fd = open(read_filename, O_RDONLY)) == -1){
		perror("afile open failed\n"); 
	}
	else{
		file_size = lseek(read_fd, 0, SEEK_END);
		close(read_fd);
		printf("file size : %d\n", (int)file_size);
	}
	
	
	return 0;
}
