#include <stdio.h>
#include <stdlib.h>
int main()
{
	int apple[10],height,num,k=0;
    for(num=0;num<=9;num++)
    {
		scanf("%d",&apple[num]);
    }
    scanf("%d",&height);
    for(num=0;num<=9;num++)
    {
		if(apple[num]<=height+30)
        {
			k++;
        }
    }
    printf("%d\n",k);
	system("pause");
	return 0;
}
