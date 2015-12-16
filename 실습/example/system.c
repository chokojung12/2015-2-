#include  <sys/types.h>  /* system.c */
#include  <sys/wait.h>
#include  <errno.h>
#include  <unistd.h>

int system(const char *cmdstring)  /* version without signal handling */
{
	pid_t pid;  int status;

	if (cmdstring == NULL)
        	return(1);    /* always a command processor with Unix */

	if ( (pid = fork()) < 0) {
		status = -1;  /* probably out of processes */
	} 
	else if (pid == 0) {        /* child */
		execl("/bin/bash", "sh", "-c", cmdstring, (char *) 0);   /* shell’s –c : take next command-line argument as its command input instead reading from standard input or a given file */
		_exit(127);    /* execl error */
	} 
	else {              /* parent */
		while (waitpid(pid, &status, 0) < 0){
			if (errno != EINTR) {
				status = -1; /* error other than EINTR from waitpid() */
				break;
			}
		}
		
	}
	return(status);
	
}
int main(int argc, char *argv[]) {
	system(argv[1]);
} 
