#include <unistd.h>
#include <stdio.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
	FILE *write_fp;
	char buffer[BUFSIZ + 1];
	
	sprintf(buffer, "once upon a time, there was...\n");
	write_fp = popen("od -c", "w");
	if(write_fp != NULL){
		fwrite(buffer, sizeof(char), strlen(buffer), write_fp);
		pclose(write_fp);
		exit(EXIT_SUCCESS);
	}
	exit(EXIT_SUCCESS);
	
}
