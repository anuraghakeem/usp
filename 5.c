#include<stdio.h>
#include<dirent.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int fd,size;
	struct dirent *dir;
	DIR *dp;
	dp=opendir(".");
	if(dp){
		while((dir=readdir(dp))!=NULL){
		fd=open(dir->d_name,O_RDWR,0777);
		size=lseek(fd,0,SEEK_END);
		if(size==0)
		unlink(dir->d_name);
		}
	}
}

