#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    scanf("%d",&x);
    printf("���λ��Ϊ��%d\nʮλ��Ϊ��%d\n��λ��Ϊ��%d",x%10,x/10%10,x/100%10);
    return 0;
}
