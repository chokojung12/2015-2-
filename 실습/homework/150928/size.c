#include <fcntl.h>         
#include <unistd.h>        

int main()
{
	int fd;
        off_t size_file;

	fd = open( "./test.txt", O_RDONLY);

	size_file = lseek(fd, 0, SEEK_END);      
	printf("The size of test.txt is %d bytes\n", size_file);

	close(fd);

	return 0;
}
