#include <stdio.h>
#include <stdlib.h>

int main()
{
    float x;
    scanf("%f",&x);
    x*=10;
    printf("%d",(int)x%10>4?(int)(x/10+1):(int)(x/10));
    return 0;
}
