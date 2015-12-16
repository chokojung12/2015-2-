#include <unistd.h>

int main(){
	symlink("original.txt", "dup.txt");
	return 0;
}
