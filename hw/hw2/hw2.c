#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

int main(){

	char c ;
	int count = 0 , counta = 0 , counte = 0, counti= 0, counto = 0, countu = 0, countdigit = 0 , countspace = 0;
	while((c=getchar())!=EOF){
			
		c = tolower(c);
		
		if(c=='a')
				counta++;
		else if(c=='e')
				counte++;
		else if(c=='i')
				counti++;
		else if(c=='o')
				counto++;
		else if(c=='u')
				countu++;
		else if(c=='1'||c=='2'||c=='3'||c=='4'||c=='5'||c=='6'||c=='7'||c=='8'||c=='9'||c=='0')
				countdigit++;
		else if(c==' '||c=='\n'||c=='\t')
				countspace++;
		
		count++;
		
	
	
	};
	
	char f[5]={'a','e','i','o','u'};
	char a[5]={'0','0','0','0','0'};
	int i , cp = 0;
	int m[5] ={counta,counte,counti,counto,countu};
	
	for (i=0;i<5;i++)
	{
		if(m[i]>cp)
			cp = m[i];
	}

	for(i=0;i<5;i++)
	{
		if(m[i]==cp&&cp!=0)
			a[i]=f[i];
	}
	
	if(counta!=0)
		printf("a:%.6f\n",(float)counta/(float)count);
	else printf("a:0\n");
	
	if(counte!=0)
		printf("e:%.6f\n",(float)counte/(float)count);
	else printf("e:0\n");
		
	if(counti!=0)
		printf("i:%.6f\n",(float)counti/(float)count);
	else printf("i:0\n");
		
	if(counto!=0)
		printf("o:%.6f\n",(float)counto/(float)count);
	else printf("o:0\n");
		
	if(countu!=0)
		printf("u:%.6f\n",(float)countu/(float)count);
	else printf("u:0\n");
		
	if(countdigit!=0)
		printf("digit:%.6f\n",(float)countdigit/(float)count);
	else printf("digit:0\n");
		
	if(countspace!=0)
		printf("space:%.6f\n",(float)countspace/(float)count);
	else printf("space:0\n");

	printf("most common vowel:");
	
	bool twice = 0;
	for(i=0;i<5;i++)
		{	
			if(a[i]!='0')
			{	
				if(twice)
					printf(",%c",a[i]);
				else
				{	printf("%c",a[i]);
					twice = 1;
				}				
			}
		}

	printf("\n");
	
	return 0;
}
