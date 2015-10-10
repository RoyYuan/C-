#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

struct coordinate
{
    int x;
    int y;
    int z;
}a[4],b[4][2],c[4];

double distance(struct coordinate m,struct coordinate n)
{
    double dis=0;
    dis=(m.x-n.x)*(m.x-n.x)+(m.y-n.y)*(m.y-n.y)+(m.z-n.z)*(m.z-n.z);
    dis=sqrt(dis);
    return dis;
}

double judge(double x[3],int y)
{
    int i,s=0;
    double max=x[0],min=x[0];
    for(i=1;i<3;i++)
    {
        if(x[i]>=max)
        {
            max=x[i];
        }
        if(x[i]<min)
            min=x[i];
    }
    for(i=0;i<3;i++)
    {
        if(min==x[i])
            s++;
    }
    if(y==1)
        return max;
    if(y==0)
    {
        if(s==2)
            return min;
        else
            return -1;
    }
    return 0;
}

int angle(struct coordinate m,struct coordinate n)
{
    if(m.x*n.x+m.y*n.y+m.z*n.z==0)
        return 0;
    else
        return 1;
}

int main()
{
    int t,o,i,flag=0;;
    double dis[4][3],f[4]={0};
    scanf("%d",&t);
    for(o=0;o<t;o++)
    {
        flag=0;
        memset(dis,0,12*sizeof(double));
        memset(f,0,4*sizeof(double));
        for(i=0;i<4;i++)
        {
            scanf("%d%d%d",&a[i].x,&a[i].y,&a[i].z);
        }
        dis[0][0]=distance(a[0],a[1]);
        dis[0][1]=distance(a[0],a[2]);
        dis[0][2]=distance(a[0],a[3]);
        dis[1][0]=distance(a[1],a[0]);
        dis[1][1]=distance(a[1],a[2]);
        dis[1][2]=distance(a[1],a[3]);
        dis[2][0]=distance(a[2],a[0]);
        dis[2][1]=distance(a[2],a[1]);
        dis[2][2]=distance(a[2],a[3]);
        dis[3][0]=distance(a[3],a[0]);
        dis[3][1]=distance(a[3],a[1]);
        dis[3][2]=distance(a[3],a[2]);
        for(i=0;i<4;i++)
        {
            f[i]=judge(dis[i],1);
        }
        for(i=0;i<3;i++)
        {
            if(f[i]!=f[i+1])
            {
                flag=1;
                break;
            }
        }
        for(i=0;i<4;i++)
        {
            f[i]=judge(dis[i],0);
            if(f[i]==-1)
            {
                flag=1;
                break;
            }
        }
        for(i=0;i<3;i++)
        {
            if(f[i]!=f[i+1])
            {
                flag=1;
                break;
            }
        }
        if(flag==1)
        {
            printf("Case #%d: No\n",o+1);
            continue;
        }
        else
        {
            printf("Case #%d: Yes\n",o+1);
        }
    }
    return 0;
}
