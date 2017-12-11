#include<stdio.h>
#include<string.h>
#define lim 50 
int getword(char *x,int max)
{
	int i=0,c,flag=0;
	while((c=getchar())!=EOF)
	{
		if(i<max && ((c>=65&&c<=90)||(c>=97&&c<=122)))
		{	
			flag=1;
			x[i]=c;
			i++;
		}
		else if(flag) break;
	}
	x[i]='\0';
	return i;
}

int weight(char *c)
{
	int i,sum=0,len = strlen(c);
	for(i=0;i<len;i++)
		sum += c[i];
	return sum;

}

int main(){
	
	int len,max=0,count=0;
	float avg = 0;
	char unit[lim];
	char longest[lim];
	while((len=getword(unit,lim))>0)
	{
		count++;
		avg += len;
		if(len>max)
		{	max=len;
			strcpy(longest,unit);
		}
		else if(len==max)
		{
			char cmp[lim];
			strcpy(cmp,unit);
			int a=weight(longest);
			int b=weight(cmp);
			if(a<b) strcpy(longest,cmp);		
		}
	}
	
	printf("The longest word: %s\n",longest);
	printf("Average word length: %.2f\n",avg/count);

return 0;
}
