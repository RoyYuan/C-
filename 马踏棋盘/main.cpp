#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 64

bool visit[8][8];
int step[8][8];
int jump[8][2]= {{1,-2},{2,-1},{2,1},{1,2},{-1,2},{-2,1},{-2,-1},{-1,-2}};

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

//��ʼ��ջ
void Stack_init()
{
    S.top=1;
    S.data[0]=origin;
}

//��ջ
void Stack_in(Coor x)
{
    S.data[S.top]=x;
    S.top++;
    return;
}

//��ջ
Coor Stack_out()
{
    S.top--;
    return S.data[S.top];
}

//�ж�ջ�Ƿ�Ϊ��
bool Stack_empty()
{
    if(S.top)
        return 0;
    else
        return 1;
}

//�ж�λ���Ƿ�Ϸ�
bool Coor_judge(Coor k)
{
    if(k.x<0 || k.x>7)
        return 0;
    if(k.y<0 || k.y>7)
        return 0;
    if(visit[k.x][k.y])
        return 0;
    return 1;
}

bool imitate()
{
    bool f=0;
    int i,j;
    int sum=1;
    Stack_init();
    now=origin;
    Stack_in(now);
    while(sum<=N && !Stack_empty())
    {
        f=0;
        next.t=-1;
        for(i=now.t+1; i<8; i++)
        {
            next.x=now.x+jump[i][0];
            next.y=now.y+jump[i][1];
            now.t=i;
            if(Coor_judge(next))
            {
                f=1;
                break;
            }
        }
        if(!f && sum!=N)
        {
            visit[now.x][now.y]=0;
            step[now.x][now.y]=0;
            Stack_out();
            now=S.data[S.top-1];
            sum--;
            for(i=0; i<8; i++)
            {
                for(j=0; j<8; j++)
                    printf("%d\t",step[i][j]);
                printf("\n");
            }
            system("pause");
        }
        else
        {
            visit[next.x][next.y]=1;
            step[next.x][next.y]=sum;
            Stack_in(next);
            now=next;
            sum++;
        }
    }
    if(Stack_empty())
    {
        printf("�޷��ҵ��Ϸ�·����\n");
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
                printf("%d\t",step[i][j]);
            printf("\n");
        }
        return 0;
    }
    else
    {
        printf("�Ϸ�·�����£�\n");
        for(i=0; i<8; i++)
        {
            for(j=0; j<8; j++)
                printf("%d\t",step[i][j]);
            printf("\n");
        }
        return 1;
    }
}

int main(void)
{
    memset(visit,0,sizeof(visit));
    memset(step,0,sizeof(step));
    printf("�������ʼλ�á�\n");
    printf("X:");
    scanf("%d",&origin.x);
    origin.x--;
    printf("Y:");
    scanf("%d",&origin.y);
    origin.y--;
    origin.t=-1;
    visit[origin.x][origin.y]=1;
    imitate();
    return 0;
}
