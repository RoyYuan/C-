#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
   int num; //�����Ž�������
   int code;//���������������
   struct Node *next;//�����һ�����ĵ�ַ
}node;
int main()
{
   int m,n,i,j;
   node *p,*q,*first;
   printf("�������ʼ�������������\n");
   scanf("%d%d",&m,&n);
   for(i=1;i<=n;i++)
   {
        if(i==1)
        {
            first=p=(node*)malloc(sizeof(node));
            if(p==0)
                return 0;
        }
        else
        {
            q=(node*)malloc(sizeof(node));
            if(q==0)
                return 0;
            p->next=q;
            p=q;
        }
        printf("�������%d���˵����롣\n",i);
        scanf("%d",&p->code);
        p->num=i;
   }
   p->next=first; //�ñ�βָ���ͷ�γ�ѭ������
   p=first;
   printf("���γ��У�");
   for (j=1;j<=n;j++)
   {
        for(i=1;i<m;i++,p=p->next);
        m=p->code;
        printf("%d ",p->num);
        p->num=p->next->num;
        p->code=p->next->code;
        q=p->next;
        p->next=p->next->next;
        free(q);
   }
   return 0;
}
