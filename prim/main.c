#include <stdio.h>
#include <stdlib.h>
#define inf 999

int main()
{
    int m,n,min,i,j,book[10]={0},d[10],e[10][10],t1,t2,t3,s=0,sum=0;
    //ȷ���������ͱ���
    printf("�����붥�����Լ�����:����������Ҫ����9����\n");
    scanf("%d%d",&m,&n);
    //��ʼ��
    for(i=1;i<=m;i++)
        for(j=1;j<=m;j++)
            if(i==j)
                e[i][j]=0;
            else
                e[i][j]=inf;
    //¼���Ȩ
    printf("���������Ȩ����ʽΪ�������� ������ ��Ȩ��:\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
        e[t1][t2]=t3;
        e[t2][t1]=t3;

    }
    //��ʼ��d����
    for(i=1;i<=m;i++)
        d[i]=e[1][i];
    //Prim�㷨��ʼ
    book[1]=1;
    s++;
    while(s!=m)
    {
        min=inf;
        for(i=1;i<=m;i++)
        {
            if(book[i]==0 && d[i]<min)
            {
                j=i;
                min=d[i];
            }
        }
        book[j]=1;
        s++;
        sum+=min;
        for(i=1;i<=m;i++)
        {
            if(book[i]==0 && d[i]>e[j][i])
                d[i]=e[j][i];
        }
    }
    printf("��С������Ȩ֮��Ϊ��%d",sum);
    return 0;
}
