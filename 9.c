#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<string.h>
int main(int argc, char *argv[]){
int fd1,fd2,size;
char buf[100];
if((fd1=open(argv[1],O_RDONLY))<0)
printf("error openign file1\n");
if((fd2=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC))<0)
printf("error opening file2\n");
size=lseek(fd1,0,SEEK_END);
lseek(fd1,0,SEEK_SET);
if((read(fd1,&buf,size))!=size)
	printf("error reading file\n");
if((write(fd2,buf,size))!=size)
	printf("error writing file\n");
else
	printf("writing done\n");

}

