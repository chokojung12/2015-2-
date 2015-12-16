#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
int main(){

	int pid;
        int status;
	    
	pid = fork();
	        
	if (pid < 0){
		perror("fork error : ");
		 exit(0);
	}
	if (pid == 0){
		printf("I am Child\n");
		sleep(2);
		return 2;
	}
	else{
	        printf("Parent: wait (%d)\n", pid);
		        waitpid(pid, &status, 0);
			        if (WIFEXITED(status)){
				            printf("d»óá");
					                printf("¸®Å°ª %d\n", WEXITSTATUS(status));
							        }
								        else if (WIFSIGNALED(status)){
									            printf("½Å£¹޾Ò½\n");
										                printf("½Å£¹ød\n", WTERMSIG(status));
												        }
													    }
													        exit(0);
														}


