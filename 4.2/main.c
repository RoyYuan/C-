#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    scanf("%d",&x);
    printf("�����Ϊ");
    if(!x)
        printf("0��\n");
    else
    {
        printf(x>0?"��":"��");
        printf(x%2==0?"ż��":"����""��\n");
    }
    return 0;
}
