#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    scanf("%d",&x);
    printf("其个位数为：%d\n十位数为：%d\n百位数为：%d",x%10,x/10%10,x/100%10);
    return 0;
}
