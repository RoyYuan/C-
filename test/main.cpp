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

//��ʼ��ջ
void Stack_init()
{
    S.top=1;
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
        //�ж���һ��
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
            //��ǰ����ջ
            Stack_in(now);
            sum++;
            step[now.x][now.y]=sum;
            visit[now.x][now.y]=1;
            //��һ����
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
    //�ж��Ƿ����
    if(sum==N)
    {
        printf("�Ϸ�·�����£�\n");
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
    printf("�������ʼλ�á�\n");
    printf("X:");
    scanf("%d",&origin.x);
    printf("Y:");
    scanf("%d",&origin.y);
    origin.t=-1;
    imitate();
    return 0;
}
