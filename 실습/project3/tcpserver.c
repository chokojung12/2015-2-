#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/stat.h>
#include <arpa/inet.h>
#include <signal.h>

#define MAXBUF  256

void handler(int sig)
{
	pid_t pid;
	int status;

	pid = wait(&status);

	printf("%d번 자식 프로세스가 종료되었습니다\n", pid);
}

float computation(char *rcv_buf){
	char *token;
	char *num1;
	char *op;
	char *num2;
	float x, y;
	float result;
	// 입력받은 문자열 쪼개기	
	token = strtok(rcv_buf, " ");
	num1 = token;
	token = strtok(NULL, " ");
	op = token;
	token = strtok(NULL, " ");
	num2 = token;
	
	x = atof(num1);
	y = atof(num2);
	
	if(!(strcmp(op,"+")))
		result = x + y;
	else if(!(strcmp(op,"-")))
		result = x - y;
	else if(!(strcmp(op,"*")))
		result = x * y;
	else if(!(strcmp(op,"/")))
		result = x / y;
	else{
		return ;
	}
	
	return result;
}

int main()
{
	int ssock, csock;
	int clen;
	pid_t pid;
	
	struct sockaddr_in client_addr, server_addr;
	char send_buf[MAXBUF], rcv_buf[MAXBUF];
	
	// client address size 
        clen = sizeof(client_addr);

	//set
	memset(&server_addr, 0, sizeof(server_addr));
	server_addr.sin_family  = AF_INET;
	server_addr.sin_addr.s_addr = htonl(INADDR_ANY);
	server_addr.sin_port    = htons(3317);

						
	signal(SIGCHLD, (void *) handler);

	/* 소켓 생성 */
	if ((ssock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
		perror("socket error : ");
		exit(1);
	}

	/* 서버 옵션 설정 */
	
	if (bind(ssock, (struct sockaddr *)&server_addr, sizeof(server_addr)) < 0) {
		perror("bind error : ");
		exit(1);
	}

	if (listen(ssock, 5) < 0) {
		perror("listen error : ");
		exit(1);
	}

	printf("계산기 프로그램 서버\n");
	
	while(1) {
		/* 연결 처리 */
		csock = accept(ssock, (struct sockaddr *)&client_addr, &clen);
		/* fork()를 이용하여 multi-process 방식으로 통신 처리 */
		pid = fork();
		
		memset(send_buf, '\0', sizeof(send_buf));
		memset(rcv_buf, '\0', sizeof(rcv_buf));
		
		switch(pid)
		{
			case -1:
			/* fork 함수 에러 발생 */
				perror("fork error : ");
				exit(1);
			case 0:
			/* 자식 프로세스의 클라이언트 소켓 처리 */
				close(ssock);
				pid = getpid();
				printf("%d번 프로세스에 새로운 소켓이 연결되었습니다\n", pid);
			
				while(read(csock, rcv_buf, MAXBUF) > 0){
					float result;
					if(!(strcmp(rcv_buf, "exit"))){
						printf("%d번 프로세스 소켓의 연결이 종료되었습니다\n", pid);
						exit(1);
					}
					result = computation(rcv_buf);	
					sprintf(send_buf, "%f", result);
					write(csock, send_buf, MAXBUF);
				}		
			default:
			/* 부모 프로세스의 클라이언트 소켓 제거 */
				close(csock);
				break;
				
		}
		
	}
	
	return 0;																			
}

