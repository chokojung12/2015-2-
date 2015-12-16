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
	
	printf("온도 변화 프로그램\n");
	printf("사용법 숫자 입력 후 F나C입력\n");
	printf("F, C는 대문자여야만 합니다.\n");
	printf("예시: 14F, 16C, 18.45F, 153.1F 등 소수점도 입력가능\n");
	slen = sizeof(server_address);

	
	printf("온도 입력: ");
	memset(send_buffer, '\0', sizeof(send_buffer));
	fgets(send_buffer, sizeof(send_buffer) ,stdin);
	sendto(client_socket, send_buffer, strlen(send_buffer), 0, (struct sockaddr*)&server_address, sizeof(server_address));
			
	
	
	memset(receive_buffer, '\0', sizeof(receive_buffer));
	
	
	recvfrom(client_socket, (void *)receive_buffer, BUFFER_SIZE, 0, (struct sockaddr *)&server_address, &slen);	
	if(receive_buffer[0] == '!'){
		printf("format error\n");
		close(client_socket);
		exit(0);
	}
	else{
		printf("변환 된 온도 : %s\n", receive_buffer);
	}
	//close socket
	close(client_socket);	

	return 0;
}
