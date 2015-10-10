#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    scanf("%d",&x);
    printf("这个数为");
    if(!x)
        printf("0。\n");
    else
    {
        printf(x>0?"正":"负");
        printf(x%2==0?"偶数":"奇数""。\n");
    }
    return 0;
}
