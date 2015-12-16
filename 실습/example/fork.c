#include <stdio.h>
#include <unistd.h>

int main(){
	int x;

	x = 0;
	fork();
	x = 1;
	printf("i'm process %ld and my x is %d\n", (long)getpid(), x);
	return 0;
}
