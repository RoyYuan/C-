#include <stdio.h>
#include <stdlib.h>

#define f(x) (*(data+x))

int *data;
int length;
int n;

void dp(int num,int last,int s)
{
    if(num==n)
    {
        if(s>length)
        {
            length=s;
        }
        return;
    }
    if(f(num)>last)
    {
        dp(num+1,f(num),s+1);
    }
    dp(num+1,last,s);
    return;
}
int main()
{
    int i;
    scanf("%d",&n);
    data=(int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++)
        scanf("%d",data+i);
    dp(0,0,0);
    printf("%d\n",length);
    return 0;
}
