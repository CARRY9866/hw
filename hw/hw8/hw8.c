#include<stdio.h>
#define size 1001
void removed(char *B)
{
	int n=0,i;
	while(B[n]!='\n')n++;
	//去尾
	for(i=n-1;i>=0;i--)
		if(B[i]==' '||B[i]=='\t')B[i]='\0';
		else break;
	n=i+1;
	//去頭
	int s=0;
	while(B[s]==' '||B[s]=='\t')s++;
	for(i=s;i<n;i++)
		B[i-s]=B[i];
	n=n-s;
	B[n]='\0';
	//去中間
	int count=0,j,flag=0;
	for(i=0;i<n;i++)
	{
		if(B[i]==' '||B[i]=='\t')
		{	flag=1;count++;}
		else flag=0;
		if((flag==0)&&(count>=1))
		{
			if(count==1)count=0;
			if(count>1)
			{
				for(j=i;j<n;j++)
					B[j-count+1]=B[j];
				n=n-count+1;
				B[n]='\0';
				count=0;
			}
		}
	}
	
}

void reverse(char *B)
{
	int n=0,i;
	while(B[n]!='\0')n++;
	for(i=0;i<n/2;i++)
	{
		char c = B[i];
		B[i]=B[n-1-i];
		B[n-1-i]=c;
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
