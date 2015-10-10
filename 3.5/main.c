#include <stdio.h>
#include <stdlib.h>

int main()
{
    float a[4],s=0,av;
    int i;
    for(i=0;i<=3;i++)
    {
        scanf("%f",&a[i]);
        s+=a[i];
    }
    printf("%f",av=s/4);
    return 0;
}
