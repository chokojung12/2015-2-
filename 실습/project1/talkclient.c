#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>

#define BUFFER_SIZE  256

int main(){
	int client_socket;
	int slen;
	struct sockaddr_in client_address, server_address;
	char send_buffer[BUFFER_SIZE], receive_buffer[BUFFER_SIZE];
	
	//create socket
	if ((client_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0) {
		perror("socket error : ");
		exit(1);								
	}
	
	//set server
	memset(&server_address,0, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_address.sin_port = htons(4100);


	slen = sizeof(server_address);

	printf("종료 채팅창에 !입력\n");

	while(1){
		//send messgae
		while(1){
			memset(send_buffer, '\0', sizeof(send_buffer));
			printf("send message to server : ");
			fgets(send_buffer, BUFFER_SIZE,stdin);
			
			if(send_buffer[0] == '!'&&send_buffer[1] == '\n'){
				printf("exit\n");
				sendto(client_socket, send_buffer, strlen(send_buffer), 0, (struct sockaddr*)&server_address, sizeof(server_address));
				close(client_socket);
				exit(0);
			}
			break;
			
		}
		sendto(client_socket, send_buffer, strlen(send_buffer), 0, (struct sockaddr*)&server_address, sizeof(server_address));
		
		memset(receive_buffer, '\0', sizeof(receive_buffer));
		recvfrom(client_socket, (void *)receive_buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_address, &slen);	
		if(receive_buffer[0] == '!' && receive_buffer[1] == '\n'){
			printf("exit\n");
			close(client_socket);
			exit(0);
		}
		printf("receive message from server : %s", receive_buffer);
	}
	
	//close socket
	close(client_socket);	

	return 0;
}
