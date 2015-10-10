#include <stdio.h>

int main()
{
    int give,cost,change,sum,s=0;
    int x[7],i;
    scanf("%d%d",&give,&cost);
    change=give-cost;
    sum=change;
    x[1]=sum/100;
    if(x[1])
        s++;
    sum=sum%100;
    x[2]=sum/50;
    if(x[2])
        s++;
    sum=sum%50;
    x[3]=sum/20;
    if(x[3])
        s++;
    sum=sum%20;
    x[4]=sum/10;
    if(x[4])
        s++;
    sum=sum%10;
    x[5]=sum/5;
    if(x[5])
        s++;
    sum=sum%5;
    x[6]=sum;
    if(x[6])
        s++;
    sum=s;
    printf("%d\n",change);s
    for(i=1;i<=6;i++)
    {
        if(x[i])
        {
            switch (i){
                case 1:printf("100");   break;
                case 2:printf("50");    break;
                case 3:printf("20");    break;
                case 4:printf("10");    break;
                case 5:printf("5");     break;
                case 6:printf("1");     break;
            }
            printf("*%d",x[i]);
            sum--;
            if(sum)
                printf("+");
        }
    }
    printf("=%d\n",change);
    return 0;
}
