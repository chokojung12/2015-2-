#include <unistd.h>
main()
{ 
	printf("executing ls\n");
  	execl("/bin/ls", "ls", "-l", (char *) 0); // 앞에경로, ls는 파일, -l은 옵션
    	perror("execl failed to run ls\n"); // 뒤에 뭐가있건 exec때문에 의미가 없어 진다.
      	exit(1);
}
