//计算1到100之间奇数和以及偶数和
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x,ji=0,ou=0;
    for(x=1;x<=100;x+=2)
    {
        ji+=x;
    }
    for(x=2;x<=100;x+=2)
    {
        ou+=x;
    }
    printf("1到100间奇数和为%d，偶数和为%d",ji,ou);
    return 0;
}
