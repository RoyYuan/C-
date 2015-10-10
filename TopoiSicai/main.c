#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int i,j,t1,t2,d[15][15],book[20]={0},m,n,a[20]={0},s=0,f;
    //初始化
    memset(d,0,sizeof(int)*15*15);
    //录入数据
    printf("请输入顶点数与边数。\n");
    scanf("%d%d",&m,&n);
    printf("请输入DAG图数据，格式为点序 点序：\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d%d",&t1,&t2);
        d[t2][t1]=1;//存储入度
    }
    //找到第一个点
    for(i=1;i<=m;i++)
    {
        f=0;
        for(j=1;j<=m;j++)
        {
            if(d[i][j]!=0)
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            book[i]=1;
            for(j=1;j<=m;j++)
            {
                d[j][i]=0;
            }
            s++;
            a[s]=i;
            break;
        }
    }
    //找其他点
    while(s!=m)
    {
        for(i=1;i<=m;i++)
        {
            f=0;
            for(j=1;j<=m;j++)
            {
                if(d[i][j]!=0)
                {
                    f=1;
                    break;
                }
            }
            if(f==0 && book[i]==0)
            {
                book[i]=1;
                for(j=1;j<=m;j++)
                {
                    d[j][i]=0;
                }
                s++;
                a[s]=i;
                break;
            }
        }
    }
    //输出结果
    printf("经拓扑排序后结果为：\n");
    for(i=1;i<=m;i++)
        printf("%d\t",a[i]);
    return 0;
}
