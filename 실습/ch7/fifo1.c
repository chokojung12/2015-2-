#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
	int res = mkfifo("a", 0775);
	if (res == 0) 
		printf("fifo created\n");
	exit(EXIT_SUCCESS);
}
			
