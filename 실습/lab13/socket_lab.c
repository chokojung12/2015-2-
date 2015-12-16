#include <sys/types.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <stdio.h>
#include <stdlib.h>
#define NAME "socket" 
main(){
	int client_socket;
	int a;
	int len;
	struct sockaddr_un to;
	char message[] = "This is message from the client";
	// socket create
	client_socket = socket(PF_UNIX, SOCK_DGRAM, 0);
	
	//set destiny address
	to.sun_family = PF_UNIX;
	strcpy(to.sun_path, NAME);
			  
	sendto(client_socket, message, strlen(message), 0, (struct sockaddr*)&to, sizeof(struct sockaddr_un));
	close(client_socket);
}
			      
