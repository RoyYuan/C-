#include <stdio.h>
#include <stdlib.h>
int main()
{
	int pay,cost,change,a,b,c,d,e,f;
    scanf("%d %d",&pay,&cost);
    change=pay-cost;
    printf("%d\n",change);
    a=change/100;
    b=change%100/50;
    c=change%50/20;
	d=change%50%20/10;
    e=change%10/5;
    f=change%5;
    if(a>0)
		printf("100*%d+",a);
    if(b>0)
		printf("50*%d+",b);
    if(c>0)
		printf("20*%d+",c);
    if(d>0)
		printf("10*%d+",d);
    if(e>0)
		printf("5*%d+",e);
    if(f>0)
		printf("1*%d+",f);
    printf("\b=%d\n",change);	
    system("pause");
	return 0;
}
