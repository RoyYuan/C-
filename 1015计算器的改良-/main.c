#include <stdio.h>
#include <stdlib.h>

int wzx(char*a,int b)
{
    int m,n,i;
    if((*(a-1))>='0'&&(*(a-1))<='9')
    {
        m=(*(a-1))-48;
        for(i=1;i<=b;i++)
            m*=10;
        n=wzx(a-1,b+1);
        return m+n;
    }
    else
    {
        if((*(a-1))=='-')

        if(b==0)
            return 1;
        else
            return 0;
    }
}

int sswz(char*a)
{
    int i=0,n=0;
    while((*(a+i))!='\0')
    {
        if(((*(a+i))>='a'&&(*(a+i))<='z')||(((*(a+i))>='A')&&((*(a+i))<='Z')))
            n++;
    }
    return n;
}
int main()
{
    char m[999]={'\0'};
    int i,j,n[999]={0},x,s;
    gets(m);
    i=sswz(m);
    printf("%d\n",i);
    return 0;
}
