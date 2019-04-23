#include<stdio.h>
#include<string.h>
#include "stack_char.h"


int palindrome(char *sent)
{
	int i,len=strlen(sent);
	char ch;
	
	stack_t st;
	initialize(&st);
	
	for(i=0;i<len/2;i++)
	{
		push(&st,sent[i]);
	}
	
	if(len%2==1)
		i++;
	
	ch=pop(&st);
	
	while(i<len && ch==sent[i])
	{
		if(!is_empty_s(&st))
			ch=pop(&st);
			i++;
	}
	
	if(i==len)
		return 1;
	else
		return 0;
	
}

int main()
{
	char sent[100];
	
	FILE *inp;
	inp=fopen("Palindrome.txt","r");
	
	if(inp=NULL)
		printf("File cannot find!");
	else
	{
		while(fscanf(inp,"%[^\n]s"),sent != EOF);
			{
				if(palindrome(sent))
					printf("%s",sent);
			}
	}
	printf("\n");
	
	return 0;
}
