#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m=0,n,x[3]={0};
    char y,z;
    scanf("%d-%d-%d-%c",&x[0],&x[1],&x[2],&y);
    m+=x[0];
    m+=(x[1]%10)*4;
    m+=(x[1]/10)%10*3;
    m+=(x[1]/100)*2;
    m+=(x[2]%10)*9;
    m+=(x[2]/10)%10*8;
    m+=(x[2]/100)%10*7;
    m+=(x[2]/1000)%10*6;
    m+=(x[2]/10000)*5;
    n=m%11;
    if(n==10)
        z='X';
    else
        z=n+48;
    if(z==y)
        printf("Right");
    else
        printf("%d-%d-%d-%c",x[0],x[1],x[2],z);
    return 0;
}
