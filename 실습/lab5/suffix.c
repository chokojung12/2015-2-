#include <stdio.h>
#include <unistd.h>
#include <dirent.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>


int match(char *s1, char *s2);

int main(int argc, char *argv[]){
	DIR *dir_info;
	struct dirent *dir_entry;
	struct stat file_info;
	
	if(argc != 3){
		printf("argc error\n");
	}
	
	else{
		dir_info = opendir(argv[1]);
		if(dir_info != NULL){
			while(dir_entry = readdir(dir_info)){
				char *file_name = dir_entry->d_name;
			
				if(match(file_name, argv[2]) != -1){
					printf("%s\n", file_name);
					stat(argv[1], &file_info);
					printf("i-node:%d\n",file_info.st_ino);
					break;	
				}
			}	
			closedir(dir_info);
		}
		else{
			printf("not found directory\n");
		}
		
		
	}
	return 0;
}


int match(char *s1, char *s2){  
	
	int diff = strlen(s1) - strlen(s2); 
	
	if (strlen(s1) > strlen(s2))  
		return(strcmp(&s1[diff], s2) == 0); 
	else  
		return -1;
	
}
