#include <sys/types.h>
#include <sys/stat.h>



int main(int argc, char *argv[]){
	struct stat file_info;
	int return_stat;
	if ( argc != 2 ){
		perror("error");
	}
	if((return_stat = stat(argv[1], &file_info)) == -1){
		printf("stat error!\n");
		exit(0);
	}
	else{
		printf("inode: %d\n", file_info.st_ino);
		printf("mode : %d\n", file_info.st_mode);
		printf("user ID: %d\n", file_info.st_uid);
	}
	return 0;
}
