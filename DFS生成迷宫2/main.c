#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

//�����������ҵ�ֵ
#define up 8
#define down 2
#define left 4
#define right 6

int s[31][51];//���ڱ�Ǹ���
int t[31][51];//���ڼ�¼�Թ�
int sum=31*2+49*2;//���ڼ�¼�ѱ�ǵĵ���
int e[5];//���ڴ���search��δ��ǵĵ��λ��

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
    int i=0;//��i����ʾ�ڵ����ж��ٸ�δ���
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
    //�������
    if(s[me.m][me.n]==0)
    {
        sum++;
        s[me.m][me.n]=1;
    }
    //����Ϸ��ڵ�
    if(i==up && me.m>1 && s[me.m-1][me.n]==0)
    {
        sum++;
        s[me.m-1][me.n]=1;
    }
    //����·��ڵ�
    if(i==down && me.m<29 && s[me.m+1][me.n]==0)
    {
        sum++;
        s[me.m+1][me.n]=1;
    }
    //�������ڵ�
    if(i==left && me.n>1 && s[me.m][me.n-1]==0)
    {
        sum++;
        s[me.m][me.n-1]=1;
    }
    //����Ҳ��ڵ�
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
    memset(s,0,31*51*sizeof(int));//��0��ʾ��δ���
    memset(t,1,31*51*sizeof(int));//��1��ʾǽ��
    //��ʼ��ջ
    memset(z.m,0,1500);
    memset(z.n,0,1500);
    z.top=0;
    //�趨����յ�
    me.m=1;
    me.n=1;
    final.m=29;
    final.n=49;
    //ȡ�������
    srand((unsigned)time(NULL));
    //������ǲ���ǽȥ��
    s[1][1]=1;
    t[1][1]=0;
    while(sum!=31*51)//��������δ��ǵĵ�ʱ
    {
        //̽�⵱ǰλ���ڵ��Ƿ���δ��ǵĵ�
        i=search();
        //���ڵ��д���δ��ǵĵ�ʱ
        if(i>0)
        {
            //�Ƴ���ǰ���ǽ
            t[me.m][me.n]=0;
            //����ǰ����ջ
            z.m[z.top]=me.m;
            z.n[z.top]=me.n;
            z.top++;
            //�����δ��ǵ��ڵ���ѡ��һ��
            k=rand()%i+1;
            //��ǵ�ǰ����ѡ����ڵ�
            sign(e[k]);
            //��ѡȡ���ڵ���Ϊ��ǰ��
            change(e[k]);
        }
        else//��ǰ���ڵ㶼�ѱ����
        {
            //��ջ��Ϊ��ʱ
            if(z.top>0)
            {
                //ջ�����ջ
                z.top--;
                //������Ϊ��ǰ��
                me.m=z.m[z.top];
                me.n=z.n[z.top];
            }
            //��ջΪ��ʱ
            else
            {
                //���ȡһδ��ǵĵ���Ϊ��ǰ��
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
    //��ӡ�Թ�
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
