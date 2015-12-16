#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>

int match(char *s1, char *s2);


int main(int argc, char *argv[]){
	DIR *dir_fd;
	struct dirent *dp;
	char *suffix;

	
	dir_fd = opendir(argv[1]);	
	suffix = argv[2];
	
	
	if(dir_fd != NULL){
		while(dp = readdir(dir_fd))	
			if(match(dp->d_name, suffix) != -1){
				printf("%s\n", dp->d_name);
				break;
			}
	}
	closedir(dir_fd);
	return 0;
}


int match(char *s1, char *s2){  
	int diff = strlen(s1)- strlen(s2);
	if (strlen(s1) > strlen(s2))  
		return (strcmp(&s1[diff], s2) == 0);
	else  
		return -1;
}
