#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int compare(int a[7])
{
    int i,j;
    for(i=0;i<6;i++)
        for(j=i+1;j<7;j++)
        {
            if(a[i]==a[j]||a[i]==1||a[j]==1)
                return 1;
        }
    return 0;
}

int f(int a[7])
{
    int m,n,s;
    m=a[0]*1000+a[1]*100+a[2]*10+a[3];
    n=1000+a[4]*100+a[5]*10+a[1];
    s=10000+a[4]*1000+a[3]*100+a[1]*10+a[6];
    if(m+n==s)
        return 1;
    else
        return 0;
}



int main()
{
    int a[7],flag=0;
    for(a[0]=0;a[0]<10;a[0]++)
    {
        for(a[1]=0;a[1]<10;a[1]++)
        {
            for(a[2]=0;a[2]<10;a[2]++)
            {
                for(a[3]=0;a[3]<10;a[3]++)
                {
                    for(a[4]=0;a[4]<10;a[4]++)
                    {
                        for(a[5]=0;a[5]<10;a[5]++)
                        {
                            for(a[6]=0;a[6]<10;a[6]++)
                            {
                                if(compare(a))
                                    continue;
                                if(f(a))
                                {
                                    flag=1;
                                    break;
                                }
                            }
                            if(flag==1)
                                break;
                        }
                        if(flag==1)
                            break;
                    }
                    if(flag==1)
                        break;
                }
                if(flag==1)
                    break;
            }
            if(flag==1)
                break;
        }
        if(flag==1)
            break;
    }
    printf("1%d%d%d",a[4],a[5],a[1]);
    return 0;
}
