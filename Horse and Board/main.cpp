#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 64
int jump[8][2]= {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};//方向数组

typedef struct coor
{
    int x,y;
} Coor;

typedef struct STACK
{
    Coor data[65];
    int top;
} Stack;

int out[10][10];//储存每个点的出口数
bool visit[10][10];//访问记录数组
int board[10][10];//记录棋盘步数
int nows[10];//记录当前点各个方向的点的出口数
Coor start,now,next;
Stack S;

//初始化栈
void Stack_init()
{
    S.top=1;
    memset(S.data,0,sizeof(S.data));
    return;
}

//入栈
void Stack_in(Coor k)
{
    board[k.x][k.y]=S.top;
    S.data[S.top++]=k;
    visit[k.x][k.y]=1;
    return;
}

//出栈
Coor Stack_out()
{
    visit[S.data[S.top-1].x][S.data[S.top-1].y]=0;
    return S.data[--S.top];
}

//判断栈是否为空
bool Stack_empty()
{
    if(S.top==0)
        return 1;
    return 0;
}

//检测点是否合法
bool Coor_judge(int x,int y)
{
    if(visit[x][y])
        return 0;
    if(x<1 || x>8 || y<1 || y>8)
        return 0;
    return 1;
}

//求出该点有多少个出口点
int Coor_out(int x,int y)
{
    int i=0,sum=0;
    for(i=0; i<8; i++)
    {
        if(Coor_judge(x+jump[i][0],y+jump[i][1]))
        {
            sum++;
        }
    }
    return sum;
}

//模拟
void sim()
{
    int minouts,num;
    Stack_init();
    now=start;
    //如果当前点合法便入栈
    if(Coor_judge(now.x,now.y))
    {
        Stack_in(now);
    }
    while(S.top<=N)
    {
        //取栈顶的点作为当前点
        now=S.data[S.top-1];
        //在无出口且未遍历时回溯
        if(Coor_out(now.x,now.y)==0 && S.top!=N+1)
        {
            Stack_out();
            continue;
        }
        //找出合法的且出口最少的点
        minouts=8;
        num=0;
        for(int i=0; i<8; i++)
        {
            next.x=now.x+jump[i][0];
            next.y=now.y+jump[i][1];
            if(Coor_judge(next.x,next.y))
            {
                nows[i]=Coor_out(next.x,next.y);
                if(nows[i]<minouts)
                {
                    minouts=nows[i];
                    num=i;
                }
            }
        }
        next.x=now.x+jump[num][0];
        next.y=now.y+jump[num][1];
        Stack_in(next);
    }
    printf("路径为：\n");
    for(int i=1; i<9; i++)
    {
        for(int j=1; j<9; j++)
        {
            printf("%d\t",board[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    memset(visit,0,sizeof(visit));
    memset(board,0,sizeof(board));
    memset(nows,0,sizeof(nows));
    while(1)
    {
        printf("请输入初始位置。\n");
        printf("X(1~8):");
        scanf("%d",&start.x);
        printf("Y(1~8):");
        scanf("%d",&start.y);
        if(!Coor_judge(start.x,start.y))
        {
            printf("输入有误，请重新输入。\n");
            system("pause");
            system("cls");
            continue;
        }
        else
        {
            break;
        }
    }
    sim();
    return 0;
}
