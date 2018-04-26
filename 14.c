#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/stat.h>
#include<signal.h>
void callback()
{
	printf("interrupt received\n");
	signal(SIGINT,SIG_DFL);

}
int main()
{
	int ch,i=0;
	printf("enter your choice \n");
	scanf("%d",&ch);
	switch(ch)
	{
		case 1:signal(SIGINT,callback);
			   break;
		case 2:signal(SIGINT,SIG_IGN);
				break;
	}
	while(1)
	{
		printf("press ctrl+c\n");
		sleep(1);
		i++;
		if(i==10&&ch==2)
			signal(SIGINT,SIG_IGN);
	}
	exit(0);
}
