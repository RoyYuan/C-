//未完成！
#include <stdio.h>

char x[31];
int s1[31],s2[10];
int t,k;


unsigned long int sum=0;

unsigned long int f(int a,int b,int num)//计算变换b个数时有多少种
{
    int i;
    unsigned long int s=1,ss=0;
    if(b==0)
        return 1;
    if(b==num+1)//选到第b个数
    {
        s=0;
        for(i=a+1;i<t-b+num;i++)
            s+=s1[i];
        return s;
    }
    for(i=a+1;i<t-b+num;i++)//算到第num个数，未满b个数时
    {
        if(s1[i]!=0)
            s=s1[i];
        s*=f(i,b,num+1);//选下一个数
        ss+=s;
    }
    return ss;
}

unsigned long int C(int b)//算有多少种
{
    int i=0;
    unsigned long int s=1;
    if(b>k)
        return 0;
    if(b==t)//t个数全变换时
    {
        for(i=0;i<t;i++)
            if(s1[i]!=0)
                s*=s1[i];
        return s;
    }
    s=f(-1,b,0);//变换b个数时
    return s+C(b+1);//加上变换b+1个数时
}



int main()
{
    int i=0,m,n;
    t=0;
    scanf("%s %d",x,&k);
    i=k;
    while((i--)!=0)
    {
        scanf("%d %d",&m,&n);
        s2[m]++;
    }
    k=0;
    for(i=0;i<10;i++)
        if(s2[i])
            k++;
    while(x[++t]!=0);
    for(i=0;i<t;i++)
        s1[i]=s2[x[i]-48];
    sum=C(0);
    printf("%lu\n",sum);
    return 0;
}
