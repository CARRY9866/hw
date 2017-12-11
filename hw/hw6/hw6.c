#include<stdio.h>
#define size 1000
void swap(int *a,int *b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

void quicksort(int *B,int left,int right)
{	
	int i , j;

	if(left<right)
	{
		i=left;
		j=right+1;
	
		do{
			do i++;while(B[i]>B[left]);
			do j--;while(B[j]<B[left]);
			if(i<j)swap(&B[i],&B[j]);
		}while(i<j);

		swap(&B[left],&B[j]);
		quicksort(B,left,j-1);
		quicksort(B,j+1,right);
	}

}

float mysqrt(float);
float avg(int *a,int left,int right)
{
	float N=right-left+1,sum=0;
	int i;
	for(i=left;i<=right;i++)
		sum+=a[i];
	return sum/N+0.005;	
}

float std(int*a,int left,int right)
{
	float N=right-left+1,sum=0;
	int i;
	float x=avg(a,left,right);
	for(i=left;i<=right;i++)
		sum+=(a[i]-x)*(a[i]-x);
	return mysqrt(sum/N)+0.005;

}

int main(){
		
	int B[size],N=0,i;
	while(scanf("%d",&B[N])!=EOF)
		(B[N]>=0&&B[N]<10000)?(N++):(B[N]=0);
	quicksort(B,0,N-1);

	float mid;
	(N%2==0)?(mid=(B[N/2-1]+B[N/2])/2.0):(mid=B[(N-1)/2]);
	
	printf("Top 10 value\n");
	if(N>10) {for(i=0;i<10;i++)printf("%d\n",B[i]);}
	else {for(i=0;i<N;i++)printf("%d\n",B[i]);}

	printf("Max value:%d\n",B[0]);
	printf("Min value:%d\n",B[N-1]);
	printf("Mid value:%.1f\n",mid);
	printf("Avg value:%.1f\n",avg(B,0,N-1));
	printf("SD value:%.1f\n",std(B,0,N-1));
	int S=N*0.05+0.5;
	printf("90%%Avg value:%.1f\n",avg(B,S,N-1-S));
	printf("90%%SD value:%.1f\n",std(B,S,N-1-S));
	return 0;
}

float mysqrt(float N){
	float low=0,high=N,mid;
	while(high-low>0.01)
	{
		mid=(low+high)/2;
		(mid*mid>N)?(high=mid):(low=mid);
	}
return low;
}
