#include <stdio.h>
#include <stdlib.h>

int main()
{
    char a[101]={"0"};
    int i=0,b[26]={0},m=1,n=100,s,f=0;
    gets(a);
    while(a[i]!='\0')
    {
        b[a[i]-97]++;
        i++;
    }
    for(i=0;i<26;i++)
    {
        m=m>=b[i]?m:b[i];
        if(b[i]!=0&&b[i]<n)
            n=b[i];
    }
    s=m-n;
    if(s%2==0)
    {
        if(s==2)
            printf("Lucky Word\n2");
        else
            printf("No Answer\n0");
    }
    else
    {
        if(s==1)
            printf("No Answer\n0");
        else
        {
            for(i=3;i*i<=s;i+=2)
            {
                if(s%i==0)
                {
                    printf("No Answer\n0");
                    f=1;
                    break;
                }
            }
            if(f==0)
                printf("Lucky Word\n%d",s);
        }
    }
    return 0;
}
