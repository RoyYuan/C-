#include <stdio.h>

int main()
{
    int n,i;
    double sc1[10],sc2[10],gpa=0,sum=0;
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        scanf("%lf %lf",&sc1[i],&sc2[i]);
        sum+=sc1[i];
        sc1[i]*=sc2[i];
        gpa+=sc1[i];
    }
    printf("%.2f\n",gpa/sum);
    return 0;
}
