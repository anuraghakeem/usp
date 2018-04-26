#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<string.h>
int main(){
	int fd,i,size;
	char buf[30],name[20];
	printf("enter name of the file\n");
	scanf("%s",name);
	if((fd=open(name,O_RDONLY))<0){
		printf("couldn't open the file\n");
		exit(1);
	}
	if((read(fd,&buf,20))!=20){
		printf("read error\n");
		exit(1);
	}
	printf("first 20 char\n");
	printf("%s",buf);
	lseek(fd,10,SEEK_SET);
	if((read(fd,&buf,20))!=20){
		printf("read error\n");
		exit(1);
	}
	printf("20 char from 10th byte\n");
	printf("%s",buf);
	lseek(fd,10,SEEK_CUR);
	if((read(fd,&buf,20))!=20){
		printf("read error\n");
		exit(1);
	}
	printf("20 char current file offset\n");
	printf("%s",buf);
	lseek(fd,0,SEEK_SET);
	size=lseek(fd,0,SEEK_END);
	printf("file size %d \n",size);
}

