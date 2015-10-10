#include <stdio.h>
#include <stdlib.h>

void hang(int k,int p)
{
    int i;
    for(i=1;i<=(k+3)/2-p;i++)
        printf(" ");
    for(i=1;i<=p*2-1;i++)
        printf("*");
    printf("\n");
    return;
}

void jie1(int k)
{
    int i;
    for(i=1;i<3;i++)
        hang(k,i);
    return;
}
void jie2(int g)
{
    int i;
    for(i=3;i<=g;i++)
        hang(2*g-1,i);
    return;
}

void gan(int g,int gg)
{
    int i,j;
    for(i=1;i<=gg;i++)
    {
        for(j=1;j<=g;j++)
            printf(" ");
        printf("*\n");
    }
    return;
}

int main()
{
    int g,k,j,gg,i;
    printf("请依次输入圣诞树的每节的高度、总计节数、树杆高度:\n");
    if(scanf("%d%d%d",&g,&j,&gg)==3)
    {
        k=2*g-1;
        jie1(k);
        for(i=1;i<=j;i++)
            jie2(g);
        gan(g,gg);
    }
    else
        printf("数据错误！正在退出。\n");
    return 0;
}
