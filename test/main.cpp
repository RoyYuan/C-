#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 64

bool visit[10][10];
int step[10][10];
int jump[8][2]= {{-2,1},{-1,2},{1,2},{2,1},{2,-1},{1,-2},{-1,-2},{-2,-1}};

typedef struct coor
{
    int x,y;
    int t;
} Coor;

typedef struct stack
{
    Coor data[70];
    int top;
} Stack;

Stack S;
Coor origin,now,next;

//初始化栈
void Stack_init()
{
    S.top=1;
}

//入栈
void Stack_in(Coor x)
{
    S.data[S.top]=x;
    S.top++;
    return;
}

//出栈
Coor Stack_out()
{
    S.top--;
    return S.data[S.top];
}

//判断栈是否为空
bool Stack_empty()
{
    if(S.top)
        return 0;
    else
        return 1;
}

//判断位置是否合法
bool Coor_judge(Coor k)
{
    if(k.x<1 || k.x>8)
        return 0;
    if(k.y<1 || k.y>8)
        return 0;
    if(visit[k.x][k.y])
        return 0;
    return 1;
}

void imitate()
{
    int sum=0,i,j;
    bool f;
    now=origin;
    Stack_init();
    while(sum<=N && !Stack_empty())
    {
        //判断下一点
        f=0;
        for(i=now.t+1; i<8; i++)
        {
            next.t=-1;
            next.x=now.x+jump[i][0];
            next.y=now.y+jump[i][1];
            if(Coor_judge(next))
            {
                now.t=i;
                f=1;
                break;
            }
        }
        if(f)
        {
            //当前点入栈
            Stack_in(now);
            sum++;
            step[now.x][now.y]=sum;
            visit[now.x][now.y]=1;
            //下一个点
            now=next;
            continue;
        }
        else
        {
            now=Stack_out();
            visit[now.x][now.y]=0;
            sum--;
            continue;
        }
    }
    //判断是否遍历
    if(sum==N)
    {
        printf("合法路径如下：\n");
        for(i=1; i<9; i++)
        {
            for(j=1; j<9; j++)
                printf("%d\t",step[i][j]);
            printf("\n");
        }
        return ;
    }
    return;
}

int main(void)
{
    memset(visit,0,sizeof(visit));
    memset(step,0,sizeof(step));
    printf("请输入初始位置。\n");
    printf("X:");
    scanf("%d",&origin.x);
    printf("Y:");
    scanf("%d",&origin.y);
    origin.t=-1;
    imitate();
    return 0;
}
