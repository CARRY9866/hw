#include<stdio.h>
#include<string.h>
#define MaxPat 100 
#define MaxLine 1000

void usage(){

	printf("please input a correct option\n-c: print pattern counts\n-m: find lines containing a pattern\n-v: find lines not containing a pattern\n");

}

int mystrstr(char *s,char *find)
{
	char c,sc;
	int len,n=0;
	if((c=*find++)!=0){
		len = strlen(find);
		do{
			do{
				if((sc=*s++)=='\n')break;
			}while(sc!=c);
			if(strncmp(s,find,len)==0)n++;
		}while(sc!='\n');
	}
	return n;
}
int main(int argc,char **argv){

	char pat[MaxPat],line[MaxLine];
	int m=0,v=0,c=0;
	char *x="-m",*y="-v",*z="-c";
	if(argc!=3)usage();
	else
	{
		if(!strcmp(argv[1],x))m=1;
		else if(!strcmp(argv[1],y))v=1;
		else if(!strcmp(argv[1],z))c=1;
		else usage();

		strcpy(pat,argv[2]);
		int count = 0,n;
		while(fgets(line,MaxLine,stdin))
		{
			if((n=mystrstr(line,pat)))
			{
				count+=n;
				if(m)printf("%s",line);
			}
			else if(v)
			{
				printf("%s",line);
			}
		}

		if(c)
		{
			printf("%s: %d\n",pat,count);
		}
	}

return 0;}
