#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x[3][3]={0},i,s=0;
    for(i=0;i<9;i++)
        scanf("%d",x[0]+i);
    s+=x[0][0]*x[1][1]*x[2][2];
    s+=x[0][1]*x[1][2]*x[2][0];
    s+=x[0][2]*x[1][0]*x[2][1];
    s-=x[0][2]*x[1][1]*x[2][0];
    s-=x[0][1]*x[1][0]*x[2][2];
    s-=x[0][0]*x[1][2]*x[2][1];
    printf("%d",s);
    return 0;
}
