#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long int  *bird,*hunt;
long int *sum;
int *book;
long int n,m;

int get_val()
{
     int ret=0;
     char c;
     while((c=getchar())!=' '&&c!='\n')
      ret=ret*10+c-'0';
     return ret;
}

void dp(long int num)
{
    long int i;
    unsigned long int x;
    int flag;
    if(num==n)
        return;
    x=*(hunt+num);
    for(i=0;i<n;i++)
    {
        if(*(bird+i)==x)
            if(*(book+i)==0)
            {
                *(sum+num)=i+1;
                *(book+i)=1;
                flag=0;
                break;
            }
    }
    if(flag)
        *(sum+num)=-1;
    dp(num+1);
}

int main()
{
    long int i,j;
    while(scanf("%ld%ld",&n,&m)!=EOF)
    {
        bird=(unsigned long int*)malloc(sizeof(unsigned long int)*n);
        book=(int*)malloc(sizeof(int)*n);
        sum=(long int*)malloc(sizeof(long int)*n);
        hunt=(unsigned long int*)malloc(sizeof(unsigned long int)*m);
        memset(book,0,sizeof(int)*n);
        for(i=0;i<n;i++)
            scanf("%lu",bird+i);
        for(j=0;j<m;j++)
            scanf("%lu",hunt+j);
        dp(0);
        for(i=0;i<n;i++)
            printf("%ld\n",*(sum+i));
    }
    return 0;
}
