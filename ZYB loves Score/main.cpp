#include <stdio.h>

int T;
int time[5];
int error[5];
int score[5];
int sum;

int main()
{
    scanf("%d",&T);
    int t=T;
    while(t)
    {
        sum=0;
        for(int i=1;i<=4;i++)
            scanf("%d %d",&time[i],&error[i]);
        score[1]=(250-time[1])*4-error[1]*50;
        if(score[1]<400)
            score[1]=400;
        score[2]=(250-time[2])*6-error[2]*50;
        if(score[2]<600)
            score[2]=600;
        score[3]=(250-time[3])*8-error[3]*50;
        if(score[3]<800)
            score[3]=800;
        score[4]=(250-time[4])*10-error[4]*50;
        if(score[4]<1000)
            score[4]=1000;
        sum=score[1]+score[2]+score[3]+score[4];
        printf("Case #%d: %d\n",T-t+1,sum);
        t--;
    }
    return 0;
}
