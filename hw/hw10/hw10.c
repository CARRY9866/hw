#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define row 1001
#define col 1001
void swap(char *a,char *b)
{
    char tmp[col];
    strcpy(tmp,a);
    strcpy(a,b);
    strcpy(b,tmp);
}

void selectionsort(char B[row][col],int n)
{
    int i,j,min;
    for(i=0;i<n-1;i++)
    {   
        min=i;
        for(j=i;j<n;j++)
        {
            if(strcmp(B[j],B[min])==-1)
            min=j;
        }
        if(min!=i)
        swap(B[i],B[min]);
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