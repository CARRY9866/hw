#include<stdio.h>
#include<string.h>
#define MaxPat 100 MaxLine 1000

void usage(){

	puts("please input a correct option
		  -c: print pattern counts
		  -m: find lines containing a pattern
		  -v: find lines not containing a pattern");

}
int main(int argc,char *argv){

	char pat[MaxPat],line[MaxLine];
	int m=0,v=0,c=0;
	char *x="-m",*y="-v",*z="-c";
	if(argc!=3)usage();
	if(!strcmp(argv[1],x))m=1;
	else if(!strcmp(argv[1],y))v=1;
	else if(!strcmp(argv[1],z))c=1;
	else usage();
	
	pat=argv[2];
	


return 0;}
