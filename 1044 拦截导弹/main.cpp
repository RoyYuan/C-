#include <stdio.h>
#include <stdlib.h>
#define f(x) (*(data+x))

int sum;
int max;
int *data;
int n=0;
int longest;

void times(int num,int last,int s)
{
    if(num==n)
    {
        if(s>longest)
            longest=s;
        return;
    }
    else if(last<=*(data+num) )
    {
        times(num+1,*(data+num),s+1);
    }
        else;
            times(num+1,last,s);
    return;
}

void dfs(int limit,int num,int s)
{
    if (num==n) {
        if (s>max) {
            max=s;
        }
        return;
    }
    if (limit-f(num)>=0) {
        dfs(f(num), num+1, s+1);
    }
    dfs(limit, num+1, s);
    return;
}

int main(int argc, const char * argv[]) {
    max=0;
    data=(int*)malloc(sizeof(int)*20);
    while (scanf("%d",(data+n))!=EOF) {
        n++;
    }
    dfs(30000, 0, 0);
    times(0, 0, 0);
    printf("%d\n%d\n",max,longest);
    return 0;
}
