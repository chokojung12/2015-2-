#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <error.h>
#define BUFFER_SIZE 256

int main(){
	int server_socket;
	int clen;
	struct sockaddr_in server_address, client_address;
	char send_buffer[BUFFER_SIZE], receive_buffer[BUFFER_SIZE];

	//creat socket
	if((server_socket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) < 0){
		perror("socket error: ");
		exit(1);
	}

	//server set
	memset(&server_address, 0, sizeof(server_address));
	server_address.sin_family = AF_INET;
	server_address.sin_addr.s_addr = htonl(INADDR_ANY);
	server_address.sin_port = htons(4100);


	//bind
	if(bind(server_socket, (struct sockaddr *)&server_address, sizeof(server_address)) < 0){
		perror("bind error");
		exit(1);
	}

	clen = sizeof(client_address);

	printf("서버와 클라이언트가 채팅을 주고받는 프로그램 입니다.\n");
	printf("blocking 방식으로 클라이언트가 먼저 메세지를 보내고 그다음 서버가 응답하는 식입니다.\n");
	printf("서버측에서 먼저 메세지를 보내면 안됩니다.\n");
	printf("종료시 한쪽에서 !입력하면 양쪽 둘다 종료 됩니다.\n");
	printf("구현기능: 서버와 클라이언트 채팅, 종료 기능\n");	
	printf("종료: 채팅창에 !입력\n");


	// send, receive message, exit
	while(1){
		//receive message
		memset(receive_buffer, '\0', sizeof(receive_buffer));
		recvfrom(server_socket, (void *)receive_buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_address, &clen);
		
		//client exit request
		if(receive_buffer[0] == '!' && receive_buffer[1] == '\n'){
			printf("exit\n");
			close(server_socket);
			exit(0);
		}
		
		printf("receive message from client : %s", receive_buffer);
	
		//send message
		while(1){
			memset(send_buffer,'\0',sizeof(send_buffer));
			printf("send message to client : ");
			fgets(send_buffer, BUFFER_SIZE, stdin);
			
				
			// exit control
			if(send_buffer[0] == '!' && send_buffer[1] == '\n'){
				printf("exit\n");
				sendto(server_socket, send_buffer, strlen(send_buffer), 0, (struct sockaddr *)&client_address, sizeof(client_address));
				close(server_socket);
				exit(0);
			}	
			break;
			
		}
		sendto(server_socket, send_buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_address, sizeof(client_address));

	}
	//close socket
	close(server_socket);
	
	return 0;
}
