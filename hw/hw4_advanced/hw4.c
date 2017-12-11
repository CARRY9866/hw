#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int main()
{

	int adjust(int x) //調分函式
	{
		float r=0 , step=0.01;
		while(r*r<=x)
		{
			r=r+step;
		}
	
		return 10*((r-0.01)+0.05);
	}

	//讀檔

	int input[3000];	
	int x,i=0,r=0,c;

	char s ;
	char n[12];
	char name[101][12];

	do{
		scanf("%s",n);
		strcpy(name[r],n);
		r++;

		for(c=0;c<3;c++)
		{
			scanf("%d",&x);
			input[i]=x;
			i++;
		}
	}while((s=getchar())!=EOF);

	const int inputsize = i-3 ;	// 總輸入成績個數
	const int size = inputsize/3;		// 總學生數

	//成績分類
	
	int score[size][4];
	int j,k;
	
	for(j=0;j<3;j++)
	{
		for(i=j,k=0;i<inputsize;i=i+3,k++)
		{
			score[k][j]=adjust(input[i]);
		}
	}


 //計算學生個人平均成績
	for(i=0;i<=size;i++)
	{
		score[i][3]=(score[i][0]+score[i][1]+score[i][2])*1.0/3 + 0.5;	
	}


//置換函式
	
	void swap(int *a , int *b)
	{
		int tmp;
		tmp = *a ;
		*a = *b;
		*b = tmp;	
	
	}

	void swapstr(char a[12] , char b[12])
	{
		char tmp[12];
		strcpy(tmp,a);
		strcpy(a,b);
		strcpy(b,tmp);
	}

//bubble sort

	for(i=0;i<size-1;i++)
	{
		bool flag = 0;	
		for(j=0;j<size-1-i;j++)
		{
			if(score[j][3]<score[j+1][3])
			{
				for(k=0;k<4;k++)
				{
					swap(&score[j][k],&score[j+1][k]);
				}
				
				swapstr(name[j],name[j+1]);
			}
			flag = 1;
		}
		if(!flag)
			break;
	}

//計算全班單科平均成績

	int amm[3][4];
	for(i=0;i<4;i++)
	{
		int sum = 0;
		for(j=0;j<size;j++)
		{
			sum += score[j][i]; 
		}
		amm[0][i]=sum*1.0/size+0.5;
	}

//找最大值

	for(i=0;i<4;i++)
	{
		amm[1][i]=score[0][i];
		for(j=0;j<size;j++)
		{
			if(amm[1][i]<score[j][i])
				amm[1][i]=score[j][i];
		}
		
	}

//找最小值

	for(i=0;i<4;i++)
	{
		amm[2][i]=score[0][i];
		for(j=0;j<size;j++)
		{
			if(amm[2][i]>score[j][i])
				amm[2][i]=score[j][i];
		}
		
	}


//print出結果
	printf("Name\tMath\tEnglish\tProg\tAverage\n----------------------------------------\n");
	for(i=0;i<size;i++)
	{
		printf("%s\t",name[i]);
		for(j=0;j<3;j++)
			printf("%d\t",score[i][j]);
		printf("%d",score[i][j]);
		printf("\n");
	}
	printf("----------------------------------------\n");
	
	printf("Avg\t");
	for(i=0;i<3;i++)
		printf("%d\t",amm[0][i]);
	printf("%d",amm[0][i]);

	printf("\nMax\t");
	for(i=0;i<3;i++)
		printf("%d\t",amm[1][i]);
	printf("%d",amm[1][i]);

	printf("\nMin\t");
	for(i=0;i<3;i++)
		printf("%d\t",amm[2][i]);
	printf("%d",amm[2][i]);
	
	printf("\n");

	return 0;



}
