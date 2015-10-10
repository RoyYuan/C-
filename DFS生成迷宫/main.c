#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <time.h>
#include <stdbool.h>
#include <stdlib.h>

//�����������ҵ���ֵ
#define up 8
#define down 2
#define left 4
#define right 6

//����洢ǽ����Ϣ������
bool t[21][51];
//����洢���Ƿ��ǵ�����
bool s[21][51];
//�������ڴ洢δ����ڵ㷽�������
int evn[5];
//�����ǵ��¼��
int sum=0;
//���巽����
int direction=0;
//����洢δ����ڵ����ı���
int nb=0;

//����ṹ��
struct coordinate
{
    int x;
    int y;
}origin,final,me;

//ջ
struct stack
{
    int top;
    struct coordinate k[1581];
}stk;

//̽�⺯��
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
    //����δ����ڵ�����
    return num;
}

//��ȥǽ�ڵĺ���
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

//�ƶ���ǰ�㺯��
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

//�Թ����ɺ���
void mazecreate()
{
    int ran,m,n;
    //�������
    origin.x=0;
    origin.y=0;
    //�����յ�
    final.x=20;
    final.y=50;
    //��ʼ������
    memset(t,false,1581);
    memset(s,false,1581);
    //��ʼ��ջ
    stk.top=0;
    //����ǰλ���������
    me.x=origin.x;
    me.y=origin.y;
    //��ȥ�����յ��ǽ��
    t[origin.x][origin.y]=true;
    t[final.x][final.y]=true;
    //ȡʱ������
    srand((unsigned)time(NULL));
    //����ѭ��
    do
    {
        if(!s[me.x][me.y])
        {
            //��ǰ����ջ
            stk.k[stk.top++]=me;
            //��ǵ�ǰ��
            s[me.x][me.y]=true;
            sum++;
        }
        //̽����Χδ����ڵ�
        nb=explore();
        if(nb!=0)
        {
            //���ȡ����
            ran=rand()%nb+1;
            direction=evn[ran];
            //��ȥǽ
            cancle();
            //�ƶ���ǰ�㵽ѡ���ڵ�
            move();
            //�ڵ���ջ
            stk.k[stk.top++]=me;
            //��ȥѡ���ڵ�ǽ
            t[me.x][me.y]=true;
            //���ѡ���ڵ�
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

//��ӡ�Թ�����
void mazeprint()
{
    int i,j;
    for(i=1;i<=53;i++)
        printf("��");
    printf("\n");
    for(i=0;i<21;i++)
    {
        printf("��");
        for(j=0;j<51;j++)
        {
            if(t[i][j])
            {
                printf("  ");
            }
            else
            {
                printf("��");
            }
            if(j==50)
                printf("��\n");
        }
    }
    for(i=1;i<=53;i++)
        printf("��");
    printf("\n");
}
int main()
{
    mazecreate();
    mazeprint();
    return 0;
}

