#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<string.h>
void charatatime(char*);
int main(){
	pid_t pid;
	int c;
	if((pid=fork())<0)
		printf("fork error\n");
	else if(pid==0){
		charatatime("child child child child child child child \n");
	
	}
	else
		charatatime("PARENT PARENT parent parent parent parent\n");
	exit(0);
}
void charatatime(char *str){
	char *ptr;
	int c;
	setbuf(stdout,NULL);
	for(ptr=str;(c=*ptr++)!=0;)
		putc(c,stdout);
}

