#include <stdio.h>
#include <stdlib.h>

int main()
{
    int ptr,day;
    float rtp=0,rtpd=0.01;
    ptr=1e5*30;
    for(day=1;day<=30;day++)
    {
        rtp+=rtpd;
        rtpd*=2;
    }
    printf("这个月陌生人给了百万富翁%d元\n这个月百万富翁给了陌生人%.2f元",ptr,rtp);
    return 0;
}
