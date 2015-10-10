#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
   int num; //代表编号结点的数据
   int code;//代表密码结点的数据
   struct Node *next;//代表后一个结点的地址
}node;
int main()
{
   int m,n,i,j;
   node *p,*q,*first;
   printf("请输入初始密码和总人数。\n");
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
        printf("请输入第%d个人的密码。\n",i);
        scanf("%d",&p->code);
        p->num=i;
   }
   p->next=first; //让表尾指向表头形成循环链表
   p=first;
   printf("依次出列：");
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
