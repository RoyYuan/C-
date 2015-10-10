#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data[1000];
    int h;
    int t;
};

struct stack
{
    int data[10];
    int top;
};

int main()
{
    int i,book[10]={0},t;
    struct queue q1,q2;
    struct stack z;
    q1.h=0; q1.t=0;
    q2.h=0; q2.t=0;
    z.top=0;
    for(i=0;i<6;i++)
        scanf("%d",&q1.data[q1.t++]);
    for(i=0;i<6;i++)
        scanf("%d",&q2.data[q2.t++]);
    while(q1.h<q1.t && q2.h<q2.t)
    {
        t=q1.data[q1.h];
        if(book[t]==0)
        {
            z.data[z.top++]=t;
            q1.h++;
            book[t]++;
        }
        else
        {
            q1.h++;
            q1.data[q1.t++]=t;
            book[t]--;
            while(z.data[z.top]!=t)
            {
                q1.data[q1.t++]=z.data[z.top];
                book[t]--;
                z.top--;
            }
        }

        t=q2.data[q2.h];
        if(book[t]==0)
        {
            q2.h++;
            book[t]++;
            z.data[z.top++]=t;
        }
        else
        {
            q2.h++;
            q2.data[q2.t++]=t;
            book[t]--;
            while(z.data[z.top]!=t)
            {
                q2.data[q2.t++]=z.data[z.top];
                book[t]--;
                z.top--;
            }
        }
    }
    if(q1.h==q1.t)
        printf("Íæ¼Ò2Ó®¡£\n");
    else
        printf("Íæ¼Ò1Ó®¡£\n");
    return 0;
}
