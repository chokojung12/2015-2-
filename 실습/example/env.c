#include <stdlib.h> /* viewenv.c */
#include <stdio.h>

extern char **environ;

int main()
{
	char **env = environ;

	while(*env){
		printf("%s\n",*env);
		env++;
	}
	exit(0);
}
								
