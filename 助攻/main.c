#include <stdio.h>
//Ϊл���������
/*int main()
{
    int j,t;
    t=(90-(30*2))/2;
    j=30-t;
    printf("����%dֻ��������%dֻ��",j,t);
    return 0;
}*/

/*int main()
{
    int y=1998;
    float l=1.011,r=50.0;
    while(r<=100)
    {
        r*=l;
        y++;
    }
    printf("��%d�꣬�����˿�ͻ��100�ڡ�",y);
    return 0;
}*/

int main()
{
    int i,j,f,n=0;
    for(i=101;i<200;i+=2)
    {
        f=0;
        for(j=2;j<i;j++)
        {
            if(i%j==0)
            {
                f=1;
                break;
            }
        }
        if(f==0)
        {
            if(n!=0 && n%5==0)
                printf("\n");
            printf("%d ",i);
            n++;
        }
    }
    return 0;
}
