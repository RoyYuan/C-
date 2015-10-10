#include <stdio.h>
#include <stdlib.h>

#define INF 9999
int main()
{
    int s[10][10],length[10],father[10],book[10]={0},t1,t2,t3,i,j,m,n,min,c,d;
    //��ȡ�ص����
    printf("������ص�����Լ�������\n");
    scanf("%d%d",&m,&n);
    //��ʼ��
    length[1]=0;
    for(i=1;i<=m;i++)
        for(j=1;j<=m;j++)
        {
            father[j]=1;//�����е����һ�㶼����ΪԴ��
            if(i==j)
                s[i][j]=0;//s[x][x]����ʼ��Ϊ0
            else
                s[i][j]=INF;//���඼��ʼ��ΪINF
        }
    //��ȡ�߳�
    printf("������߳�����ʽΪ���ص��� �ص��� ���ȡ���\n");
    for(i=1;i<=n;i++)
    {
        scanf("%d %d %d",&t1,&t2,&t3);
        s[t1][t2]=t3;
    }
    //��length�����ʼ��
    for(i=1;i<=m;i++)
        length[i]=s[1][i];
    //dijkstra�㷨
    for(i=2;i<=m;i++)
    {
        //��δ��ǵĵ����ҵ������һ��
        min=INF;
        for(j=2;j<=m;j++)
        {
            if(book[j]!=1 && min> length[j])
            {
                d=j;
                min=length[j];
            }
        }
        //��Ǹõ�
        book[d]=1;
        //�������߽����ɳڲ���
        for(j=2;j<=m;j++)
            if(min+s[d][j]<length[j])
            {
                length[j]=min+s[d][j];
                //���õ����һ����Ϊ��;����
                father[j]=d;
            }
    }
    //���
    printf("��Դ�㵽�������̾�������Ϊ��\n");
    for(i=2;i<=m;i++)
    {
        c=father[i];
        printf("To %d:%d\t",i,length[i]);
        printf("·��Ϊ��%d <- ",i);
        while(c!=1)
        {
            printf("%d <- ",c);
            c=father[c];
        }
        printf("%d\n",1);
    }
    return 0;
}
