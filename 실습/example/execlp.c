#include <unistd.h>
#include <stdlib.h>


int main(){
	execlp("ls", "ls", (char *)0);
}
