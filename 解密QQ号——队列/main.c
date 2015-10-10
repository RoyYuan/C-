#include <stdio.h>

struct queue
{
    char d[100];
    int h;
    int t;
};

int main()
{
    int i;
    struct queue q;
    q.h=0;
    q.t=0;
    for(i=0;i<9;i++)
    {
        scanf("%c",&q.d[i]);
        q.t++;
    }
    while(q.h!=q.t)
    {
        printf("%c",q.d[q.h++]);
        q.d[q.t++]=q.d[q.h++];
    }
    return 0;
}
