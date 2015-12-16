#include <stdlib.h>
#include <unistd.h>


int main(){
	char *argv[] = {"ls", "-al", (char*)0};
	execve("/bin/ls", argv, NULL);
}
