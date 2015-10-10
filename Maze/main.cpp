#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
int moves[4][2]={{-1,0},{0,1},{1,0},{0,-1}};

//坐标
typedef struct coor
{
    int x,y;
}Coor;

//成员
typedef struct member
{
    Coor cr;
    int father,dir;
}Member;

//队列
typedef struct QUEUE
{
    int head,tail;
    Member data[100000];
}Queue;

Queue q;
bool visit[100][100];
int maze[100][100];
int m,n;
Coor start,final;
//初始化队列
void Queue_init()
{
    q.head=0;
    q.tail=0;
    memset(q.data,0,sizeof(q.data));
}

//判断队列是否为空
bool Queue_empty()
{
    if(q.head==q.tail)
        return 1;
    return 0;
}

//入队
void Queue_in(Member k)
{
    q.data[q.tail++]=k;
    visit[k.cr.x][k.cr.y]=1;
}

//出队
Member Queue_out()
{
    return q.data[q.head++];
}

//判断位置是否合法
bool Coor_judge(Coor k)
{
    if(k.x>=0 && k.x<n && k.y>=0 && k.y<m && visit[k.x][k.y]==0 && maze[k.x][k.y]!=1)
        return 1;
    return 0;
}

int bfs()
{
    Member now,next;
    Queue_init();
    now.cr=start;
    now.father=-1;
    Queue_in(now);
    while(!Queue_empty())
    {
        //队首出队
        now=Queue_out();
        next.father=q.head-1;
        if(now.cr.x==final.x && now.cr.y==final.y)
        {
            printf("成功找到最短出路。\n");
            return q.head-1;
        }
        //找到能走的方向并入队
        for(int i=0;i<4;i++)
        {
            next.cr.x=now.cr.x+moves[i][0];
            next.cr.y=now.cr.y+moves[i][1];
            next.dir=i;
            if(Coor_judge(next.cr))
            {
                Queue_in(next);
            }
        }
    }
    printf("没有出路。\n");
    return -1;
}

int main()
{
    //freopen("out.txt","w",stdout);
    int steps,d;
    char temp;
    int c;
    memset(visit,0,sizeof(visit));
    memset(maze,0,sizeof(maze));
    printf("请依次输入迷宫的宽度和高度（<=100）。\n");
    scanf("%d%d",&m,&n);
    printf("请输入迷宫信息，以S表示起点，F表示终点，#表示墙壁,.表示道路。\n");
    for(int i=0;i<n;i++)
    {
        while((c = getchar()) != '\n' && c != EOF);
        for(int j=0;j<m;j++)
        {
            scanf("%c",&temp);
            switch(temp)
            {
            case 'S':
            case 's':   start.x=i;  start.y=j;  maze[i][j]=2;   break;
            case 'F':
            case 'f':   final.x=i;  final.y=j;  maze[i][j]=3;   break;
            case '#':   maze[i][j]=1;   break;
            }
        }
    }
    steps=bfs();
    if(steps!=-1)
    {
        d=q.data[steps].dir;
        steps=q.data[steps].father;
        while(q.data[steps].father!=-1)
        {
            switch(d)
            {
                case 0:maze[q.data[steps].cr.x][q.data[steps].cr.y]=11; break;
                case 1:maze[q.data[steps].cr.x][q.data[steps].cr.y]=12; break;
                case 2:maze[q.data[steps].cr.x][q.data[steps].cr.y]=13; break;
                case 3:maze[q.data[steps].cr.x][q.data[steps].cr.y]=14; break;
            }
            d=q.data[steps].dir;
            steps=q.data[steps].father;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                switch(maze[i][j])
                {
                    case 0:printf(" "); break;
                    case 1:printf("#"); break;
                    case 2:printf("S"); break;
                    case 3:printf("F"); break;
                    case 11:printf("%c",24);    break;
                    case 12:printf("%c",26);    break;
                    case 13:printf("%c",25);    break;
                    case 14:printf("%c",27);    break;
                }
            }
            printf("\n");
        }
    }
    return 0;
}
