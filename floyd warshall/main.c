#include <stdio.h>
#include <stdlib.h>

#define inf 999
int main()
{
    int e[10][10],i,j,k,t1,t2,t3,m,n;
    //ȷ���ص����������
    printf("������ص�������ߵĸ��������ص�����������Ϊ9����\n");
    scanf("%d%d",&m,&n);
    //��ʼ������
    for(i=1;i<=m;i++)
        for(j=1;j<=m;j++)
        {
            if(i==j)
                e[i][j]=0;
            else
                e[i][j]=inf;
        }
    //¼�볤������
    printf("������߳�����ʽΪ���ص��� �ص��� ���ȡ���\n");
    for(i=0;i<n;i++)
    {
        scanf("%d%d%d",&t1,&t2,&t3);
        e[t1][t2]=t3;
    }
    //floyd�����㷨
    for(i=1;i<=m;i++)
        for(j=1;j<=m;j++)
            for(k=1;k<=m;k++)
                if(e[j][k]>e[j][i]+e[i][k])
                    e[j][k]=e[j][i]+e[i][k];
    //���
    printf("�������ó����·��Ϊ��\n");
    for(i=1;i<=m;i++)
        printf("\t%d",i);
    printf("\n");
    for(i=1;i<=m;i++)
    {
        printf("%d\t",i);
        for(j=1;j<=m;j++)
            printf("%d\t",e[i][j]);
        printf("\n");
    }
    return 0;
}
