#include <stdlib.h>    /*environ.c*/                                                        
#include <stdio.h>                                                             
#include <string.h>                                                            
                                                                               
int main(int argc, char *argv[]){                                                                              
	char *var, *value;                                                     

	if(argc == 1 || argc >2) {                                             
		fprintf(stderr,"usage: environ var [value]\n");                
		exit(1);                                                       
	}
	
	var = argv[1];
	value = getenv(var);
		
	if(value != NULL)
		printf("%S=%s\n", var, value);
	if(value == NULL)
		printf("%s\n", var);
	
	
	return 0;
}
