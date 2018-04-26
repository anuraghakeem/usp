#include<stdio.h>
#include<fcntl.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<unistd.h>
#include<string.h>
#include<stdlib.h>
#include<dirent.h>
int main(int argc, char *argv[]){
	if(argc==3){
		printf("creating hard link between %s and %s \n",argv[1],argv[2]);
		if(link(argv[1],argv[2])==0)
		printf("link created\n");
		else
		printf("link not created\n");
	}
	
	if(argc==4){
		printf("creating soft link n=between %s and %s ",argv[1],argv[2]);
		if(symlink(argv[1],argv[2])==0)
		printf("soft link created\n");
		else
		printf("soft link not created\n");

	}
}

