#include <stdio.h>


void message1(void);
void message2(void);

int main(){
	if(atexit(message1)){
		printf("first\n");
	}
	else if(atexit(message2)){
		printf("second\n");
	}
}






void message1(void){
	printf("message1\n");
}
void message2(void){
	printf("message2\n");
}
