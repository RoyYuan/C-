#include <stdio.h>
#include <stdlib.h>
#define inf 999

int main()
{
    int m,n,min,i,j,book[10]={0},d[10],e[10][10],t1,t2,t3,s=0,sum=0;
    //确定顶点数和边数
    printf("请输入顶点数以及边数:（顶点数不要超过9个）\n");
    scanf("%d%d",&m,&n);
    //初始化
    for(i=1;i<=m;i++)
        for(j=1;j<=m;j++)
            if(i==j)
                e[i][j]=0;
            else
                e[i][j]=inf;
    //录入边权
    printf("请输入各边权，格式为“顶点编号 顶点编号 边权”:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
        e[t1][t2]=t3;
        e[t2][t1]=t3;

    }
    //初始化d数组
    for(i=1;i<=m;i++)
        d[i]=e[1][i];
    //Prim算法开始
    book[1]=1;
    s++;
    while(s!=m)
    {
        min=inf;
        for(i=1;i<=m;i++)
        {
            if(book[i]==0 && d[i]<min)
            {
                j=i;
                min=d[i];
            }
        }
        book[j]=1;
        s++;
        sum+=min;
        for(i=1;i<=m;i++)
        {
            if(book[i]==0 && d[i]>e[j][i])
                d[i]=e[j][i];
        }
    }
    printf("最小生成树权之和为：%d",sum);
    return 0;
}
