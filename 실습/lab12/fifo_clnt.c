#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_FILE "myfifo"
#define FAIL -1
#define BUFFER_SIZE 1024

int main( void)
{
	int fd;
   	char buffer[BUFFER_SIZE];

   	if (( fd = open( FIFO_FILE, O_WRONLY))==FAIL)
   	{
   		perror( "open failed\n");
		exit( 1);
   	}
	while(1){
   		write(fd, buffer, BUFFER_SIZE);
		memset(buffer, '\0',BUFFER_SIZE);
	}
	close(fd);
	return 0;
}
