#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#define NAME "socket"
	  
	    
main(){
	int sock, length, fromlen;
	struct sockaddr_un name, from;
	char buf[1024];
		    
	sock = socket(PF_UNIX, SOCK_DGRAM, 0);
	name.sun_family = PF_UNIX;
	strcpy(name.sun_path, NAME);
	
	fromlen = sizeof(from);
	
	bind(sock, (struct sockaddr *)&name, sizeof(struct sockaddr_un));
	printf("socket %s\n", NAME);
	memset(buf, '\0' ,1024);
	recvfrom(sock, buf, 1024, 0, (struct sockaddr *)&from, &fromlen);
	printf("%s\n", buf);
	unlink(NAME);//bind 에러 방지를 위해서
	close(sock);
}
			       
