#include <stdio.h>
//根据鱼的深度变化做出不同输出 
int main(int argc, char *argv[])
{
	int d1,d2,d3,d4;
	scanf("%d %d %d %d",&d1,&d2,&d3,&d4);
	if(d1>d2 && d2>d3 && d3>d4)
	{
		printf("Fish Diving");
	}
	else
	{	
		if(d1<d2 && d2<d3 && d3<d4)
		{
			printf("Fish Rising");
		}
		else
		{
			if(d1==d2 && d2==d3 && d3==d4)
			{
			printf("Fish At Constant Depth");
			}
			else
			{	
				printf("No Fish");
			}
		}
	}
	return 0;
}
