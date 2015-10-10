#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct stack
{
    char d[100];
    int top;
};

int anagram(int k)
{
    int m,len,mid,i,flag=0;
    struct stack hui;
    hui.top=0;
    memset(hui.d,0,sizeof(char)*100);
    m=k;
    while(m)
    {
        hui.d[hui.top++]=(m%10)+48;
        m/=10;
    }
    len=strlen(hui.d);
    mid=len/2;
    for(i=len-1;i>=len-mid;i--)
    {
        m=k%10;
        k/=10;
        if(hui.d[i]!=m+48)
            flag=1;
    }
    if(flag)
        return 0;
    else
        return 1;

}

int main()
{
    int m,n,i,sum=0;
    while(scanf("%d",&m)!=EOF)
    {
        scanf("%d",&n);
        sum=0;
        for(i=m;i<=n;i++)
        {
            if(anagram(i))
            {
                sum++;
            }
        }
        printf("%d\n",sum);
    }
    return 0;
}
