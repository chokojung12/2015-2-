#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <string.h>

#define MAXBUF  256
  
int main()
{
	int ssock;
	int clen, num=0;
	struct sockaddr_in server_addr;
	char send_buf[MAXBUF], rcv_buf[MAXBUF];
	char *num1, num2;
	char op;
	memset(rcv_buf, '\0', sizeof(rcv_buf));
	
	//create socket
	if ((ssock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket error : ");
		exit(1);
	}
											 
	clen = sizeof(server_addr);
	
	//set
	memset(&server_addr,0, sizeof(server_addr));
	server_addr.sin_family 	= AF_INET;
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	server_addr.sin_port 	= htons(3317);
	
	//connect
	if (connect(ssock, (struct sockaddr *)&server_addr, clen) < 0) {
		perror("connect error :");
		exit(1);
	}

	printf("계산기 프로그램 클라이언트\n ");
	printf("입력 예시: 숫자 연산자 숫자\n");	
	printf("반드시 숫자와 연산자 사이에 공백을 둘것\n");
	printf("입력 예시: 10 * 10\n");
	printf("입력 예시: 3 / 10\n");
	printf("입력 예시: 15 + 10\n");
	printf("종료:exit 입력\n");
	while(1){
		memset(send_buf, '\0', sizeof(send_buf));
		memset(rcv_buf, '\0', sizeof(rcv_buf));
		printf("입력: ");
		fgets(send_buf, MAXBUF, stdin);	
		printf("%s",send_buf);
		if(send_buf[0] == 'e' && send_buf[1] =='x' && send_buf[2] == 'i', send_buf[3] == 't' && send_buf[4] == '\n'){
			printf("종료 합니다\n");
			write(ssock, send_buf, MAXBUF);
			close(ssock);
			exit(1);
		}
		write(ssock, send_buf, MAXBUF);
		read(ssock, rcv_buf, MAXBUF);
		printf("결과: %s\n", rcv_buf);
			
	}
	
							
	close(ssock);
	return 0;
	
}

																																																										
