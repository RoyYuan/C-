//人口增长
#include <stdio.h>
#include <stdlib.h>

int main()
{
    double n=0.011,people=50;
    int year=1998;
    while(people<100)
    {
        people*=(1+n);
        year++;
    }
    printf("到了%d年，世界人口突破100亿达到%.2f亿",year,people);
    return 0;
}
