#include<stdio.h>
#define size 1001

void removed(char *B)
{
	int N=0,i;
	while(B[N]!='\n')N++;
	for(i=N-1;i>0;i--)
	{
		if(B[i]==' '||B[i]=='\t')B[i]='\0';
		else break;
	}
	N=i+1;

	int s=0;
	while(B[s]==' '||B[s]=='\t')s++;
	for(i=s;i<N;i++)B[i-s]=B[i];
	N=N-s;
	B[N]='\0';

	int j,flag=0,count=0;
	for(i=0;i<N;i++)
	{
		if(B[i]==' '||B[i]=='\t'){flag=1;count++;}
		else flag=0;
		if(!flag&&count>0)
		{
			if(count==1)count=0;
			if(count>1)
			{
				for(j=i;j<N;j++)
					B[j-count+1]=B[j];
				N=N-count+1;
				B[N]='\0';
				count =0;
			}
			
		}
	}
}

void reverse(char *B)
{
	int N=0,i;
	while(B[N]!='\0')N++;
	for(i=0;i<N/2;i++)
	{	
		char c=B[i];
		B[i]=B[N-1-i];
		B[N-1-i]=c;
	}
}

int main(){
	char B[size];
	while(fgets(B,size,stdin))
	{
		removed(B);
		reverse(B);
		puts(B);
	}
return 0;}
