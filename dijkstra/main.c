#include <stdio.h>
#include <stdlib.h>

#define INF 9999
int main()
{
    int s[10][10],length[10],father[10],book[10]={0},t1,t2,t3,i,j,m,n,min,c,d;
    //获取地点个数
    printf("请输入地点个数以及边数。\n");
    scanf("%d%d",&m,&n);
    //初始化
    length[1]=0;
    for(i=1;i<=m;i++)
        for(j=1;j<=m;j++)
        {
            father[j]=1;//将所有点的上一点都暂置为源点
            if(i==j)
                s[i][j]=0;//s[x][x]都初始化为0
            else
                s[i][j]=INF;//其余都初始化为INF
        }
    //获取边长
    printf("请输入边长，格式为“地点编号 地点编号 长度”。\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&t1,&t2,&t3);
        s[t1][t2]=t3;
    }
    //将length数组初始化
    for(i=1;i<=m;i++)
        length[i]=s[1][i];
    //dijkstra算法
    for(i=2;i<=m;i++)
    {
        //在未标记的点中找到最近的一点
        min=INF;
        for(j=2;j<=m;j++)
        {
            if(book[j]!=1 && min> length[j])
            {
                d=j;
                min=length[j];
            }
        }
        //标记该点
        book[d]=1;
        //对其他边进行松弛操作
        for(j=2;j<=m;j++)
            if(min+s[d][j]<length[j])
            {
                length[j]=min+s[d][j];
                //将该点的上一点置为此途经点
                father[j]=d;
            }
    }
    //输出
    printf("从源点到各点的最短距离依次为：\n");
    for(i=2;i<=m;i++)
    {
        c=father[i];
        printf("To %d:%d\t",i,length[i]);
        printf("路径为：%d <- ",i);
        while(c!=1)
        {
            printf("%d <- ",c);
            c=father[c];
        }
        printf("%d\n",1);
    }
    return 0;
}
