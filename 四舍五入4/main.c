#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x;
    int a;
    scanf("%f",&x);
    a=(int)x;
    printf("%d",x-a>=0.5?a+1:a);
    return 0;
}
