#include <stdio.h>
#include <stdlib.h>

void exit_handler1(void)
{
	printf("exit_handler1\n");
}

void exit_handler2(void)
{
	printf("exit_handler2\n");
}

void exit_handler3(void)
{
	printf("exit_handler3\n");
}

int main(int argc, char* argv[]){
	if (atexit(exit_handler1)) 
		printf("Failed to register exit_handler1\n");
	if (atexit(exit_handler2)) 
		printf("Failed to register exit_handler2\n");
	if (atexit(exit_handler2)) 
		printf("Failed to register exit_handler2\n");
	if (atexit(exit_handler3)) 
		printf("Failed to register exit_handler3\n");

	printf("Hello\n");
								        
	return 0;
}
