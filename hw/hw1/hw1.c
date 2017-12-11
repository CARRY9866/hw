#include <stdio.h>
#include <string.h>

int main(){
	
	while(1){
		
		char key[100];
		scanf("%s",key);
		if(strcmp(key,"Hello")==0)
		{
			printf("World\n");
		}
		else if(strcmp(key,"apple")==0)
		{
			printf("蘋果\n");
		}
		else if(strcmp(key,"banana")==0)
		{
			printf("香蕉\n");
		}
		else if(strcmp(key,"orange")==0)
		{
			printf("柳丁\n");
		}
		else if(strcmp(key,"pineapple")==0)
		{
			printf("鳳梨\n");
		}
		else if(strcmp(key,"watermelon")==0)
		{
			printf("西瓜\n");
		}
		else if(strcmp(key,"grape")==0)
		{
			printf("葡萄\n");
		}
		else if(strcmp(key,"longan")==0)
		{
			printf("龍眼\n");
		}
		else if(strcmp(key,"ballet")==0)
		{
			printf("芭樂\n");
		}
		else if(strcmp(key,"chair")==0)
		{
			printf("椅子\n");
		}
		else if(strcmp(key,"door")==0)
		{
			printf("門\n");
		}
		else if(strcmp(key,"0")==0)
		{
			break;
		}
		else 
		{
			printf("李公蝦毀!?\n");
		}






	}

	return 0;
}
