#include<stdio.h>
#include<string.h>

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


	int input[3000];	//讀檔
	int x,i=0;
	
	while(scanf("%d",&x)!=EOF)
	{
		input[i]=x;
		i++;
	}
	
	const int inputsize = i ;	
	const int size = i/3;

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
	printf("No\tMath\tEnglish\tProg\tAverage\n----------------------------------------\n");
	for(i=0;i<size;i++)
	{
		printf("%d\t",i);
		for(j=0;j<4;j++)
			printf("%d\t",score[i][j]);
		printf("\n");
	}
	printf("----------------------------------------\n");
	
	printf("Avg\t");
	for(i=0;i<4;i++)
		printf("%d\t",amm[0][i]);
	
	printf("\nMax\t");
	for(i=0;i<4;i++)
		printf("%d\t",amm[1][i]);
	
	printf("\nMin\t");
	for(i=0;i<4;i++)
		printf("%d\t",amm[2][i]);
	printf("\n");


	return 0;

}
