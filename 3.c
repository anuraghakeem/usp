#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<unistd.h>
#include<string.h>
int main(){
	struct stat fs;
	char name[20];
	printf("enter the name\n");
	scanf("%s",name);
	if((stat(name,&fs))<0)
		exit(1);
	printf("file size %d\n",fs.st_size);
	printf("number of links %d\n",fs.st_nlink);
	printf("inodes %d\n",fs.st_ino);
	printf("user id %d\n",fs.st_uid);
	printf("access permissions\n");
	printf((fs.st_mode & S_IRUSR)?"r":"-");
	printf((fs.st_mode & S_IWUSR)?"w":"-");
	printf((fs.st_mode & S_IXUSR)?"x":"-");
	printf((fs.st_mode & S_IRGRP)?"r":"-");
	printf((fs.st_mode & S_IWGRP)?"w":"-");
	printf((fs.st_mode & S_IXGRP)?"x":"-");
	printf((fs.st_mode & S_IROTH)?"r":"-");
}
