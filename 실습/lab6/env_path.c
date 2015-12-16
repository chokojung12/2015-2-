#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUCESS 0

extern char **environ;

int main(){
	
	char *env_path;
	char *add_path = ":./";
	char *change_path;

	if((env_path = getenv("PATH")) != NULL){
		change_path = strcat(env_path, add_path);
		if(setenv("PATH", change_path, !0) == SUCESS){
			printf("PATH=%s\n", change_path);
			while(*environ == change_path)
				printf("%s\n", *environ);
		}
		else{
			printf("setenv failed\n");
			exit(1);
		}
	}
	
	
	else{
		printf("not found PATH\n");
		exit(1);
	}

	return 0;
}
