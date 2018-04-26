#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<string.h>
#include<sys/stat.h>
#include<unistd.h>
int main(int argc,char *argv[])
{
int fd,i,size;
char buf;
char name[10];
printf("enter the filename\n");
scanf("%s",name);
if((fd=open(name,O_RDONLY))<0)
{
    printf("couldn't open file\n");
    exit(1);
}
size=lseek(fd,0,SEEK_END);
printf("%d\n",size);
for(i=size-1;i>=0;i--)
{
    lseek(fd,(off_t)i,SEEK_SET);
    if((read(fd,&buf,1)!=1))
    {
        printf("error reading \n");
        exit(1);
    }
    printf("%c",buf);
}
printf("\n");

}

