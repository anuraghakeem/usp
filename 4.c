#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<string.h>
#include<fcntl.h>
#include<dirent.h>
#include<time.h>
int main(){
	struct stat fs;
	struct dirent *dir;
	DIR *dp;
	dp=opendir(".");
	if(dp){
	while(dir=readdir(dp)){
	stat(dir->d_name,&fs);
	printf("%d %o %d %d %s %s\n",fs.st_size,fs.st_mode,fs.st_ino,fs.st_nlink,ctime(&fs.st_atime),dir->d_name);

	}
	}

}

