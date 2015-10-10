#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a[5]={0},sum=0;
    for(a[0]=1;a[0]<10;a[0]++)
    {
        if(a[0]==4)
            continue;
        for(a[1]=0;a[1]<10;a[1]++)
        {
            if(a[1]==4)
                continue;
            for(a[2]=0;a[2]<10;a[2]++)
            {
                if(a[2]==4)
                    continue;
                for(a[3]=0;a[3]<10;a[3]++)
                {
                    if(a[3]==4)
                        continue;
                    for(a[4]=0;a[4]<10;a[4]++)
                    {
                        if(a[4]==4)
                            continue;
                        sum++;
                    }
                }
            }
        }
    }
    printf("%d",sum);
    return 0;
}
