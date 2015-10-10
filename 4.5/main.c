#include <stdio.h>
#include <stdlib.h>

int main()
{
    int s;
    scanf("%d",&s);
    if(s<90)
        if(s<70)
            if(s<60)
                printf("D。\n");
            else
                printf("C。\n");
        else
            printf("B。\n");
    else
        printf("A。\n");
    return 0;
}
