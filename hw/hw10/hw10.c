#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define row 1100
#define col 1100
void swap(char *a,char *b)
{
    char tmp[col];
    strcpy(tmp,a);
    strcpy(a,b);
    strcpy(b,tmp);
}

void selectionsort(char B[row][col],int n)
{
    int i,j,max;
    for(i=n-1;i>0;i--)
    {   
        max=i;
        for(j=i;j>=0;j--)
        {
            if(strcmp(B[j],B[max])>0)
            max=j;
        }
        if(max!=i)
        swap(B[i],B[max]);
    }
}

int main(){

    char B[row][col];
    int i,n=0;
    while(fgets(B[n],col,stdin))n++;
    selectionsort(B,n);
    for(i=0;i<n;i++)
    printf("%s",B[i]);
    
    return 0;
}
