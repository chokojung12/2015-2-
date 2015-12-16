#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <error.h>
#define BUFFER_SIZE 256

int computation_function(char *receive_buffer, char *send_buffer);

int main(){
	int server_socket;
	int clen;
	struct sockaddr_in server_address, client_address;
	char send_buffer[BUFFER_SIZE], receive_buffer[BUFFER_SIZE];
	int error_control;
	
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

	printf("온도 변환 프로그램 입니다.\n");

	
		
	//receive message
	memset(receive_buffer, '\0', sizeof(receive_buffer));
	memset(send_buffer,'\0',sizeof(send_buffer));
	recvfrom(server_socket, (void *)receive_buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_address, &clen);
	

	printf("요청받은 값: %s", receive_buffer);
	
	error_control = computation_function(receive_buffer, send_buffer);
	
	if(error_control == 1){
		sendto(server_socket, "!", sizeof("!"), 0, (struct sockaddr *)&client_address, sizeof(client_address));
		close(server_socket);
		exit(0);
	}
	
	//send message
	sendto(server_socket, send_buffer, BUFFER_SIZE, 0, (struct sockaddr *)&client_address, sizeof(client_address));
	
	close(server_socket);
	
	return 0;
}


int computation_function(char *receive_buffer, char *send_buffer){
	int i;
	float temp;
	char state;
	char temp_buffer[BUFFER_SIZE];	
	
	//format check 
	for(i = 0; receive_buffer[i] != 70 && receive_buffer[i] != 67; ++i){
		if(receive_buffer[i] >= 48 && receive_buffer[i] <= 57 || receive_buffer[i] == 46){
			if(i == 0 && receive_buffer[i] == 46){
				printf("format error\n");
				return 1;
			}
			temp_buffer[i] = receive_buffer[i];
		}
		else{
			printf("format error\n");
			return 1;
		}
	}
	if(!(receive_buffer[i-1] >=48 && receive_buffer[i-1] <= 57)){
		printf("format error\n");
		return 1;
	}
	
	//set F or C	
	state = receive_buffer[i];
	// set temp float
	temp = atof(temp_buffer);

	if(state == 'F'){
		float celsius = (temp-32)*5/9;
		sprintf(send_buffer, "%.0f%c", celsius,'C');
	}
	else if(state == 'C'){
		float fahrenheit = (temp*9/5) + 32;
		sprintf(send_buffer, "%.0f%c", fahrenheit,'F');
	}
	return 0;
}
