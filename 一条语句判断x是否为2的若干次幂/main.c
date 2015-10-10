#include <stdio.h>
#include <stdlib.h>

int main()
{
    int k;
    scanf("%d",&k);
    printf("%s",(k&(k-1))==0?"YES":"NO");
    return 0;
}
