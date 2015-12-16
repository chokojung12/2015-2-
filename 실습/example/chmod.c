#include <sys/types.h>
#include <sys/stat.h>
#include <error.h>

int main()
{
  struct stat    statbuf;

    /* turn on set-group-ID and turn off group-execute */

      if (stat("foo", &statbuf) < 0)
          perror("stat(foo)");
	    if (chmod("foo", (statbuf.st_mode & ~S_IXGRP) | S_ISGID) < 0)
	        perror("chmod(foo)");

		  /* set absolute mode to "rw-r--r--" */

		    if (chmod("bar", S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH) < 0)
		        perror("chmod(bar)");

			  return 0;
			  }
			  
