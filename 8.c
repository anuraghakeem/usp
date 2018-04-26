#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<setjmp.h>
#include<fcntl.h>
void f1(int, int, int, int);
static int globval;
static jmp_buf jmpbuffer;
int main(){
	volatile int volaval=1;
	register int regval=2;
	static int val=3;
	globval=4;
	printf("before longjump globval=%d regval=%d volaval=%d staticval=%d\n",globval,regval,volaval,val);
	if(setjmp(jmpbuffer)!=0){
	
	printf("after long jmp globval=%d regval=%d volaval=%d staticval=%d\n",globval,regval,volaval,val);
	exit(0);
	}
	globval=95,regval=96,volaval=97,val=98;
	f1(globval,regval,volaval,val);
	}
	void f1(int i, int j, int k, int l){
	printf("in f1()\n");
	globval=1000;
	j=9999;
	longjmp(jmpbuffer,1);
	}

