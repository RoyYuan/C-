#include <stdio.h>
#include <string.h>

int main()
{
	char sentance[10000];
	gets(sentance);
	int len = strlen(sentance),i;
	int end,start;
	end = len;
	for(i=len;i>0;i--)
	{
		sentance [i] =sentance[i-1];
	}
	sentance[0]=' ';

	for(i=len+1;i>0;i--)
	{
		if(sentance[i-1]==' ')
		{
			for(start = i-1;start<end;start++)
			printf("%c",sentance[start+1]);
			printf(" ");
			end = i-1;
		} 
	}
return 0;
}
