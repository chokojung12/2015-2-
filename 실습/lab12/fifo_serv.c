#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>

#define FIFO_FILE "myfifo"
#define BUFFER_SIZE 1024
#define FAIL -1

int main( void)
{
	int fd;
        char buffer[BUFFER_SIZE];

	if (mkfifo( FIFO_FILE, 0777)==FAIL)
	{
		perror( "mkfifo failed\n");
		exit(1);
	}

	if ((fd = open( FIFO_FILE, O_RDWR))==FAIL)
	{
		perror("open failed\n");
		exit(1);
	}
	
	while(read(fd, buffer, BUFFER_SIZE)>0){	
		printf("%s", buffer);
		memset(buffer, '\0', BUFFER_SIZE);
	}								    
	close(fd);
	
	return 0;
}
