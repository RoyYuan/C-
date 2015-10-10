#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    char d[100];
    int top;
};

int main()
{
    int i,len,mid,m;
    char d[100];
    struct stack h;
    h.top=0;
    gets(d);
    len=strlen(d);
    mid=len%2==0?len/2-1:len/2;
    m=len/2;
    for(i=0;i<=mid;i++)
        h.d[h.top++]=d[i];
    for(i=m;i<len;i++)
        if(h.d[--h.top]!=d[i])
            break;
    if(h.top==0)
        printf("YES");
    else
        printf("No");
    return 0;
}
