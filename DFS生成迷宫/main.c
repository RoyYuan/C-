#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

//定义上下左右的数值
#define up 8
#define down 2
#define left 4
#define right 6

//定义存储墙壁信息的数组
bool t[21][51];
//定义存储点是否标记的数组
bool s[21][51];
//定义用于存储未标记邻点方向的数组
int evn[5];
//定义标记点记录数
int sum=0;
//定义方向数
int direction=0;
//定义存储未标记邻点数的变量
int nb=0;

//坐标结构体
struct coordinate
{
    int x;
    int y;
}origin,final,me;

//栈
struct stack
{
    int top;
    struct coordinate k[1581];
}stk;

//探测函数
int explore()
{
    int num=0;
    if(me.x-2>=0 && !s[me.x-1][me.y])
    {
        evn[++num]=up;
    }
    if(me.x+2<=20 && !s[me.x+2][me.y])
    {
        evn[++num]=down;
    }
    if(me.y-2>=0 && !s[me.x][me.y-2])
    {
        evn[++num]=left;
    }
    if(me.y+2<=50 && !s[me.x][me.y+2])
    {
        evn[++num]=right;
    }
    //返回未标记邻点总数
    return num;
}

//消去墙壁的函数
void cancle()
{
    switch(direction)
    {
        case up:t[me.x-1][me.y]=true;  break;
        case down:t[me.x+1][me.y]=true;    break;
        case left:t[me.x][me.y-1]=true;    break;
        case right:t[me.x][me.y+1]=true;   break;
    }
}

//移动当前点函数
void move()
{
    switch(direction)
    {
        case up:me.x-=2;    break;
        case down:me.x+=2;  break;
        case left:me.y-=2;  break;
        case right:me.y+=2; break;
        default:    ;
    }
}

//迷宫生成函数
void mazecreate()
{
    int ran,m,n;
    //给定起点
    origin.x=0;
    origin.y=0;
    //给定终点
    final.x=20;
    final.y=50;
    //初始化数组
    memset(t,false,1581);
    memset(s,false,1581);
    //初始化栈
    stk.top=0;
    //将当前位置置于起点
    me.x=origin.x;
    me.y=origin.y;
    //消去起点和终点的墙壁
    t[origin.x][origin.y]=true;
    t[final.x][final.y]=true;
    //取时间种子
    srand((unsigned)time(NULL));
    //进入循环
    do
    {
        if(!s[me.x][me.y])
        {
            //当前点入栈
            stk.k[stk.top++]=me;
            //标记当前点
            s[me.x][me.y]=true;
            sum++;
        }
        //探测周围未标记邻点
        nb=explore();
        if(nb!=0)
        {
            //随机取方向
            ran=rand()%nb+1;
            direction=evn[ran];
            //消去墙
            cancle();
            //移动当前点到选定邻点
            move();
            //邻点入栈
            stk.k[stk.top++]=me;
            //消去选定邻点墙
            t[me.x][me.y]=true;
            //标记选定邻点
            s[me.x][me.y]=true;
            sum++;
        }
        else
        {
            if(stk.top)
            {
                stk.top--;
                me=stk.k[--stk.top];
            }
            else
            {
                m=1;
                n=1;
                while(s[m][n])
                {
                    m=rand()%11;
                    m=2*m;
                    n=rand()%26;
                    n=2*n;
                    if(!s[m][n])
                    {
                        me.x=m;
                        me.y=n;
                        t[m][n]=true;
                        stk.k[stk.top++]=me;
                        s[m][n]=true;
                        break;
                    }
                }
            }
        }
    } while(me.x!=origin.x || me.y !=origin.y);
}

//打印迷宫函数
void mazeprint()
{
    int i,j;
    for(i=1;i<=53;i++)
        printf("■");
    printf("\n");
    for(i=0;i<21;i++)
    {
        printf("■");
        for(j=0;j<51;j++)
        {
            if(t[i][j])
            {
                printf("  ");
            }
            else
            {
                printf("■");
            }
            if(j==50)
                printf("■\n");
        }
    }
    for(i=1;i<=53;i++)
        printf("■");
    printf("\n");
}
int main()
{
    mazecreate();
    mazeprint();
    return 0;
}

