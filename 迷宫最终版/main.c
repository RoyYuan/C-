#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include <windows.h>

//��������������ֵ
#define up 8
#define down 2
#define left 4
#define right 6

//������Ǵ洢����
bool s[19][29];
//����ǽ����Ϣ�洢����
bool t[19][29];
//����δ����ڵ�洢����
int evn[5];
//����δ����ڵ���
int num=0;
//�������ܵ���
int sum=0;
//���巽�����
int direction=0;
//�������洢����
char in;

//��������ṹ�岢������ǰλ�á���ҡ���㡢�յ�
struct coordinate
{
    int x;
    int y;
}now,player,origin,final;

//����ջ�ṹ������
struct stack
{
    int top;
    struct coordinate k[600];
}stk;

//̽��δ����ڵ㺯��
int explore()
{
    int num=0;
    //�Ϸ�
    if(now.x-2>=0 && !s[now.x-2][now.y])
    {
        evn[++num]=up;
    }
    //�·�
    if(now.x+2<=18 && !s[now.x+2][now.y])
    {
        evn[++num]=down;
    }
    //���
    if(now.y-2>=0 && !s[now.x][now.y-2])
    {
        evn[++num]=left;
    }
    //�ұ�
    if(now.y+2<=28 && !s[now.x][now.y+2])
    {
        evn[++num]=right;
    }
    return num;
}

//��ȥ��ǰ�����ڵ���ǽ��
void cancle()
{
    switch(direction)
    {
        case up:t[now.x-1][now.y]=true;     break;
        case down:t[now.x+1][now.y]=true;   break;
        case left:t[now.x][now.y-1]=true;   break;
        case right:t[now.x][now.y+1]=true;  break;
    }
}

//��ѡ�����ڵ���Ϊ��ǰ��
void move()
{
    switch(direction)
    {
        case up:now.x-=2;    break;
        case down:now.x+=2;  break;
        case left:now.y-=2;  break;
        case right:now.y+=2; break;
    }
}

//�Թ���������
void mazecreate()
{
    int nb=0,ran,m,n;
    //��ʼ������
    memset(s,false,19*29*sizeof(bool));
    memset(t,false,19*29*sizeof(bool));
    //������㡢�յ�
    origin.x=0;
    origin.y=0;
    final.x=18;
    final.y=28;
    //��ʼ��ջ
    stk.top=0;
    //����ǰ���������
    now=origin;
    //��ǰ����ջ
    stk.k[stk.top++]=now;
    //��ǵ�ǰ�㲢��ȥ��ǰ���ǽ��
    s[now.x][now.y]=true;
    t[now.x][now.y]=true;
    sum++;
    //ȡ����
    srand((unsigned)time(NULL));
    //��δ����ʱѭ��
    while(!s[18][28] || !t[18][28] || sum!=150)
    {
        //̽����Χ�ڵ��Ƿ���δ��ǵ�
        nb=explore();
        //����δ��ǵ��ڵ�
        if(nb)
        {
            //���ȡһ��δ����ڵ�
            ran=rand()%nb+1;
            direction=evn[ran];
            //��ȥ��ǰ�����ڵ��ǽ
            cancle();
            //���ڵ���Ϊ��ǰ��
            move();
            //��ǵ�ǰ�㲢��ȥ��ǰ���ǽ��
            s[now.x][now.y]=true;
            t[now.x][now.y]=true;
            sum++;
            //��ǰ����ջ
            stk.k[stk.top++]=now;
        }
        //��û��δ��ǵ��ڵ�
        else
        {
            //��ջ��Ϊ��ʱ
            if(stk.top)
            {
                //�����ջ��Ϊ��ǰ��
                stk.top--;
                now=stk.k[--stk.top];
            }
            //��ջΪ��
            else
            {
                //���ȡһδ��ǵĵ���Ϊ��ǰ��
                m=0;
                n=0;
                while(s[m][n])
                {
                    m=(rand()%10)*2;
                    n=(rand()%15)*2;
                }
                now.x=m;
                now.y=n;
                //��ǰ����ջ
                stk.k[stk.top++]=now;
                //��ǵ�ǰ�㲢��ȥ��ǰ���ǽ��
                s[m][n]=true;
                t[m][n]=true;
                sum++;
            }
        }
    }
}

void mazeprint()
{
    int i,j;
    //��ӡ���ϲ�ǽ��
    for(i=1;i<=31;i++)
        printf("��");
        printf("\n");
    for(i=0;i<19;i++)
    {
        //��ӡ��ǽ��
        printf("��");
        for(j=0;j<29;j++)
        {
            if(i==player.x && j==player.y)
                printf("��");
            else
            {
                if(i==final.x && j==final.y)
                    printf("��");
                else
                {
                    if(t[i][j])
                        printf("  ");
                    else
                        printf("��");
                }
            }
        }
        //��ӡ�ҷ�ǽ��
        printf("��\n");
    }
    //��ӡ���·�ǽ��
    for(i=1;i<=31;i++)
        printf("��");
}

//��ӭ����
void menu()
{
    int i;
    for(i=0;i<34;i++)
        printf("��");
    printf("\n\n\n\n");
    for(i=0;i<10;i++)
        printf("  ");
    printf("��ӭʹ������Թ�����\n\n\n\n");
    for(i=0;i<34;i++)
        printf("��");
    printf("\n�������������\n");
    Sleep(3000);
    getch();
    system("cls");
    printf("������ʽΪ��\n������Ϊ8��������Ϊ2��������Ϊ4��������Ϊ6��\n");
    printf("������������Թ���\n");
    Sleep(3000);
    getch();

}

//���ߺ���
void play()
{
    //������������
    player.x=0;
    player.y=0;
    //��δ�����յ�ʱѭ��
    while(player.x!=final.x || player.y!=final.y)
    {
        //����
        in=getch();
        //���ݼ������ݣ��ж��Ƿ����ߣ����߷���
        switch(in)
        {
            case '8':if(t[player.x-1][player.y])    player.x--; break;
            case '2':if(t[player.x+1][player.y])    player.x++; break;
            case '4':if(t[player.x][player.y-1])    player.y--; break;
            case '6':if(t[player.x][player.y+1])    player.y++; break;
        }
        //���������´�ӡ�Թ�
        system("cls");
        mazeprint();
    }
    //�ߵ��յ�����ѭ�����ɹ�
    printf("\n�ɹ�����ϲ��\n");
}

int main()
{
    menu();
    system("cls");
    mazecreate();
    mazeprint();
    play();
    return 0;
}
