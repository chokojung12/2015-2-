#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <utime.h>
#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
int main(int argc, char *argv[]){
	struct dirent *dp;
	DIR *dir_fd;
	int i;
	
	while(--argc > 0){
		if(!(dir_fd = opendir(*++argv))){
			if(mkdir(*argv, S_IRWXU|S_IRWXG|S_IRWXO) == -1)
				perror("opendir");
			continue;
		}
		for(i = 0; i < 2; i++){
			int cnt = 0;
			for(;dp = readdir(dir_fd);){
				if(i)
					printf("%s\n",dp->d_name);
				if(strcmp(dp->d_name,".")&&strcmp(dp->d_name,".."))
					cnt++;
			}
		
			if(!cnt){
				rmdir(*argv);
				break;
			}
			rewinddir(dir_fd);
		}
		closedir(dir_fd);
	}
	return 0;
}
