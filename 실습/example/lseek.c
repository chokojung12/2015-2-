#include <unistd.h>

int main(){
  if (lseek(1, 0, SEEK_CUR) == -1)
      printf("cannot seek\n");
        else
	    printf("seek OK\n");
	      return 0;
	      }
	      
