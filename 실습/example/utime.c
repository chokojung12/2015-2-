#include <sys/types.h> /* utime.c */
#include <sys/stat.h>
#include <fcntl.h>
#include <utime.h>
#include "error.h"

int main(int argc, char *argv[]) {
	int    i;
	struct stat    statbuf;
      	struct utimbuf  timebuf;

        for (i = 1; i < argc; i++) {
		if (stat(argv[i], &statbuf) < 0) /* fetch current times */
	        	perror(argv[i]);

		if (open(argv[i], O_RDWR | O_TRUNC) < 0)  /* truncate */
			perror(argv[i]);

		timebuf.actime  = statbuf.st_atime;
		timebuf.modtime = statbuf.st_mtime;
		if (utime(argv[i], &timebuf) < 0)  /* reset times */
			perror(argv[i]);
	}
	return 0;
}
						  
