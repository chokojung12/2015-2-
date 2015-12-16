#include <stdlib.h>
#include <unistd.h>

int main(){
	char *argv[] = {"ls", "-al", (char *)0};
	execvp("ls", argv);
	return 0;
}
