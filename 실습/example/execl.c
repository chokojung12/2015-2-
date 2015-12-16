#include <unistd.h>

main(int argc, char *argv[]){
	execl("/bin/echo", "ehco", "fuck", "you", (char *)0);
}
