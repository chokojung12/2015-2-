#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>

#define MAXBUF  256


int main()
{
	int ssock, csock; // socket descriptor 
	int clen;
        struct sockaddr_in client_addr, server_addr; // socket is memory 
	char buf[MAXBUF] = "I like you!";  

	// create socket, descriptor is assigned by socket
	if((ssock = socket(PF_INET, SOCK_STREAM, IPPROTO_TCP)) < 0) {
		perror("socket error : ");
		exit(1);
	}

	clen = sizeof(client_addr);

	// set socket memory
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family  = AF_INET; // only ip4v use
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY); // ip
	server_addr.sin_port = htons(2000);   // port 
		
		
	// binding	
	if (bind(ssock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
		perror("bind error : ");
		exit(1);
	}

	// server open
	if (listen(ssock, 8) < 0) {
		perror("listen error : ");
		exit(1);
	}


	while(1) {
		csock = accept(ssock, (struct sockaddr *)&client_addr, &clen);  // get request
		if (write(csock, buf, MAXBUF) <=0)
			perror("write error : ");

		close(csock);
	}

	return 0;
}
											 
