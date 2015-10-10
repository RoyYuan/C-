#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//定义上下左右的值
#define up 8
#define down 2
#define left 4
#define right 6

int s[31][51];//用于标记格子
int t[31][51];//用于记录迷宫
int sum=31*2+49*2;//用于记录已标记的点数
int e[5];//用于储存search后未标记的点的位置

struct stack{
    int m[1500],n[1500];
    int top;
}z;

struct gps{
    int m;
    int n;
}me,final;

int search()
{
    int i=0;//用i来显示邻点中有多少个未标记
    if(me.m>1 && s[me.m-1][me.n]==0)
    {
        e[++i]=up;
    }
    if(me.m<29 && s[me.m+1][me.n]==0)
    {
        e[++i]=down;
    }
    if(me.n>1 && s[me.m][me.n-1]==0)
    {
        e[++i]=left;
    }
    if(me.n<49 && s[me.m][me.n+1]==0)
    {
        e[++i]=right;
    }
    return i;
}

void sign(int i)
{
    //标记自身
    if(s[me.m][me.n]==0)
    {
        sum++;
        s[me.m][me.n]=1;
    }
    //标记上方邻点
    if(i==up && me.m>1 && s[me.m-1][me.n]==0)
    {
        sum++;
        s[me.m-1][me.n]=1;
    }
    //标记下方邻点
    if(i==down && me.m<29 && s[me.m+1][me.n]==0)
    {
        sum++;
        s[me.m+1][me.n]=1;
    }
    //标记左侧邻点
    if(i==left && me.n>1 && s[me.m][me.n-1]==0)
    {
        sum++;
        s[me.m][me.n-1]=1;
    }
    //标记右侧邻点
    if(i==right && me.n<49 && s[me.m][me.n+1]==0)
    {
        sum++;
        s[me.m][me.n+1]=1;
    }
}

void change(int i)
{
    if(i==up)
        me.m--;
    if(i==down)
        me.m++;
    if(i==left)
        me.n--;
    if(i==right)
        me.n++;
}

void maze()
{
    int i,j,k,f;
    memset(s,0,31*51*sizeof(int));//用0表示尚未标记
    memset(t,1,31*51*sizeof(int));//用1表示墙壁
    //初始化栈
    memset(z.m,0,1500);
    memset(z.n,0,1500);
    z.top=0;
    //设定起点终点
    me.m=1;
    me.n=1;
    final.m=29;
    final.n=49;
    //取随机种子
    srand((unsigned)time(NULL));
    //将起点标记并将墙去除
    s[1][1]=1;
    t[1][1]=0;
    while(sum!=31*51)//当还存在未标记的点时
    {
        //探测当前位置邻点是否有未标记的点
        i=search();
        //当邻点中存在未标记的点时
        if(i>0)
        {
            //移除当前点的墙
            t[me.m][me.n]=0;
            //将当前格入栈
            z.m[z.top]=me.m;
            z.n[z.top]=me.n;
            z.top++;
            //随机从未标记的邻点中选择一点
            k=rand()%i+1;
            //标记当前点与选择的邻点
            sign(e[k]);
            //将选取的邻点作为当前点
            change(e[k]);
        }
        else//当前格邻点都已被标记
        {
            //当栈不为空时
            if(z.top>0)
            {
                //栈顶点出栈
                z.top--;
                //另它成为当前点
                me.m=z.m[z.top];
                me.n=z.n[z.top];
            }
            //当栈为空时
            else
            {
                //随机取一未标记的点作为当前点
                f=0;
                while(f==0)
                {
                    me.m=rand()%29+1;
                    me.n=rand()%49+1;
                    if(s[me.m][me.n]==0)
                        f=1;
                }
            }
        }
    }
    //打印迷宫
    for(i=0;i<31;i++)
    {
        for(j=0;j<51;j++)
        {
            if(t[i][j]==0)
                printf(" ");
            if(t[i][j]==1)
                printf("#");
        }
        printf("\n");
    }
}

int main()
{
    maze();
    return 0;
}
