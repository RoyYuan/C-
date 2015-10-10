#include <stdio.h>
#include <stdlib.h>

#define inf 999
int main()
{
    int e[10][10],i,j,k,t1,t2,t3,m,n;
    //确定地点个数、边数
    printf("请输入地点个数、边的个数。（地点个数最大限制为9个）\n");
    scanf("%d%d",&m,&n);
    //初始化矩阵
    for(i=1;i<=m;i++)
        for(j=1;j<=m;j++)
        {
            if(i==j)
                e[i][j]=0;
            else
                e[i][j]=inf;
        }
    //录入长度数据
    printf("请输入边长，格式为“地点编号 地点编号 长度”。\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
        e[t1][t2]=t3;
    }
    //floyd核心算法
    for(i=1;i<=m;i++)
        for(j=1;j<=m;j++)
            for(k=1;k<=m;k++)
                if(e[j][k]>e[j][i]+e[i][k])
                    e[j][k]=e[j][i]+e[i][k];
    //输出
    printf("经计算后得出最短路径为：\n");
    for(i=1;i<=m;i++)
        printf("\t%d",i);
    printf("\n");
    for(i=1;i<=m;i++)
    {
        printf("%d\t",i);
        for(j=1;j<=m;j++)
            printf("%d\t",e[i][j]);
        printf("\n");
    }
    return 0;
}
