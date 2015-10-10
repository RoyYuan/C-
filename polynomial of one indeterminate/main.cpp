#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1000000007

typedef struct Linklist
{
    long long int index_num;
    long long int coefficient_num;
    struct Linklist *next;
}*LinkList,LinkNode;

char input[10000];

//������
long long int quickpow(long long int m,long long int n)
{
    long long int b = 1;
    while(n>0)
    {
        if(n&1)
            b=(b*m)%N;
        n=n>>1 ;
        m=(m*m)%N;
    }
    return b;
}

//��������洢һԪ����ʽ
LinkList Create_LinkList()
{
    LinkList head,temp,temp1;
    bool flag=0,f=0;
    long long int i=0,length1,length2,mm;
    char index[100],coefficient[10];
    head=(LinkList)malloc(sizeof(LinkNode));
    temp=(LinkList)malloc(sizeof(LinkNode));
    temp->index_num=0;
    temp->coefficient_num=0;
    head->next=NULL;
    length1=0;
    length2=0;
    memset(input,0,sizeof(input));
    memset(index,0,sizeof(index));
    memset(coefficient,0,sizeof(coefficient));
    scanf("%s",input);
    /*���ַ�����ʶ��*/
    while(input[i]!='\0')
    {
        /*����⵽����ʱ*/
        if(input[i]=='-')
        {
            if(i!=0)
            {
                /*��ϵ������index*/
                int k=strlen(index),a;
                //��ϵ��Ϊ1ʱ
                if(k==0)
                {
                    temp->index_num=1;
                }
                else
                {
                    //��ϵ����Ϊ��ʱ
                    if(index[0]!='-')
                    {
                        mm=1;
                        for(a=k-1; a>=0; a--)
                        {
                            temp->index_num+=(index[a]-48)*mm;
                            mm*=10;
                        }
                    }
                    //��ϵ��Ϊ��ʱ
                    else
                    {
                        if(k==1)
                        {
                            temp->index_num=-1;
                        }
                        else
                        {
                            mm=-1;
                            for(a=k-1; a>0; a--)
                            {
                                temp->index_num=(index[a]-48)*mm;
                                mm*=10;
                            }
                        }
                    }
                }

                /*��ָ�����*/
                int t=strlen(coefficient),b;
                //��ָ��Ϊ1ʱ
                if(t==0 && f==1)
                {
                    temp->coefficient_num=1;
                }
                else
                {
                    if(t==0 && f==0)
                        temp->coefficient_num=0;
                    else
                    {
                        mm=1;
                        for(b=t-1; b>=0; b--)
                        {
                            temp->coefficient_num+=(coefficient[b]-48)*mm;
                            mm*=10;
                        }
                    }
                }

                /*�����ݴ���������*/
                temp1=head;
                if(temp1->next==NULL)
                {
                    head->next=temp;
                    temp->next=NULL;
                }
                else
                {
                    while(temp1->next!=NULL && ((temp1->next)->coefficient_num)<=(temp->coefficient_num))
                    {
                        temp1=temp1->next;
                    }
                    //ָ����ͬʱ
                    if(temp1->coefficient_num==temp->coefficient_num)
                    {
                        temp1->index_num+=temp->index_num;
                    }
                    else
                    {
                        temp->next=temp1->next;
                        temp1->next=temp;
                    }
                }
            }
            //�����µĿռ����һ�����ݲ���ʼ��
            temp=(LinkList)malloc(sizeof(LinkNode));
            temp->coefficient_num=0;
            temp->index_num=0;
            //��ʼ��ϵ��ָ���洢
            length1=0;
            length2=0;
            memset(index,0,sizeof(index));
            memset(coefficient,0,sizeof(coefficient));
            flag=0;
            f=0;
            //�����Ŵ���ϵ���洢
            index[0]='-';
            length1++;

            i++;
            continue;
        }
        /*����⵽�Ӻ�ʱ*/
        if(input[i]=='+')
        {
            /*��ϵ������index*/
            int k=strlen(index),a;
            //��ϵ��Ϊ1ʱ
            if(k==0)
            {
                temp->index_num=1;
            }
            else
            {
                //��ϵ����Ϊ��ʱ
                if(index[0]!='-')
                {
                    mm=1;
                    for(a=k-1; a>=0; a--)
                    {
                        temp->index_num+=(index[a]-48)*mm;
                        mm*=10;
                    }
                }
                //��ϵ��Ϊ��ʱ
                else
                {
                    if(k==1)
                    {
                        temp->index_num=-1;
                    }
                    else
                    {
                        mm=-1;
                        for(a=k-1; a>0; a--)
                        {
                            temp->index_num=(index[a]-48)*mm;
                            mm*=10;
                        }
                    }
                }
            }

            /*��ָ�����*/
            int t=strlen(coefficient),b;
            //��ָ��Ϊ1ʱ
            if(t==0 && f==1)
            {
                temp->coefficient_num=1;
            }
            else
            {
                if(t==0 && f==0)
                    temp->coefficient_num=0;
                else
                {
                    mm=1;
                    for(b=t-1; b>=0; b--)
                    {
                        temp->coefficient_num+=(coefficient[b]-48)*mm;
                        mm*=10;
                    }
                }
            }

            /*�����ݴ���������*/
            temp1=head;
            if(temp1->next==NULL)
            {
                head->next=temp;
                temp->next=NULL;
            }
            else
            {
                while(temp1->next!=NULL && ((temp1->next)->coefficient_num)<=(temp->coefficient_num))
                {
                    temp1=temp1->next;
                }
                //��ָ����ͬʱ
                if(temp1->coefficient_num==temp->coefficient_num)
                {
                    temp1->index_num+=temp->index_num;
                }
                else
                {
                    temp->next=temp1->next;
                    temp1->next=temp;
                }
            }

            //�����µĿռ����һ�����ݲ���ʼ��
            temp=(LinkList)malloc(sizeof(LinkNode));
            temp->coefficient_num=0;
            temp->index_num=0;
            //��ʼ��ϵ��ָ���洢
            length1=0;
            length2=0;
            memset(index,0,sizeof(index));
            memset(coefficient,0,sizeof(coefficient));
            flag=0;
            f=0;

            i++;
            continue;
        }
        /*����⵽δ֪��ʱ*/
        if((input[i]>=65 && input[i]<=90) || (input[i]>=97 && input[i]<=122))
        {
            //��ʼ��ȡָ��
            flag=1;
            f=1;
            i++;
            continue;
        }
        /*����⵽^����ʱ*/
        if(input[i]=='^')
        {
            flag=1;
            f=1;
            i++;

            continue;
        }
        /*����⵽��ʱ*/
        if(input[i]>='0' && input[i]<='9')
        {
            //���ڶ�ȡϵ��ʱ
            if(flag==0)
            {
                index[length1++]=input[i];
            }
            //���ڶ�ȡָ��ʱ
            else
            {
                coefficient[length2++]=input[i];
            }
            i++;
            continue;
        }
    }
    /*��ϵ������index*/
    int k=strlen(index),a;
    //��ϵ��Ϊ1ʱ
    if(k==0)
    {
        temp->index_num=1;
    }
    else
    {
        //��ϵ����Ϊ��ʱ
        if(index[0]!='-')
        {
            mm=1;
            for(a=k-1; a>=0; a--)
            {
                temp->index_num+=(index[a]-48)*mm;
                mm*=10;
            }
        }
        //��ϵ��Ϊ��ʱ
        else
        {
            if(k==1)
            {
                temp->index_num=-1;
            }
            else
            {
                mm=-1;
                for(a=k-1; a>0; a--)
                {
                    temp->index_num=(index[a]-48)*mm;
                    mm*=10;
                }
            }
        }
    }

    /*��ָ�����*/
    int t=strlen(coefficient),b;
    //��ָ��Ϊ1ʱ
    if(t==0 && f==1)
    {
        temp->coefficient_num=1;
    }
    else
    {
        if(t==0 && f==0)
            temp->coefficient_num=0;
        else
        {
            mm=1;
            for(b=t-1; b>=0; b--)
            {
                temp->coefficient_num+=(coefficient[b]-48)*mm;
                mm*=10;
            }
        }
    }

    /*�����ݴ���������*/
    temp1=head;
    if(temp1->next==NULL)
    {
        head->next=temp;
        temp->next=NULL;
    }
    else
    {
        while(temp1->next!=NULL && ((temp1->next)->coefficient_num)<=(temp->coefficient_num))
        {
            temp1=temp1->next;
        }
        if(temp1->coefficient_num==temp->coefficient_num)
        {
            temp1->index_num+=temp->index_num;
        }
        else
        {
            temp->next=temp1->next;
            temp1->next=temp;
        }
    }
    return head;
}

//���һԪ����ʽ
void Print_LinkList(LinkList head)
{
    LinkList temp;
    if(head==NULL || head->next==NULL)
    {
        printf("0\n");
        return;
    }
    temp=head->next;
    printf("%I64d",temp->index_num);
    if(temp->coefficient_num!=0)
        printf("*x^%I64d",temp->coefficient_num);
    temp=temp->next;
    while(temp!=NULL)
    {
        if(temp->index_num>0)
            printf("+%I64d*x^%I64d",temp->index_num,temp->coefficient_num);
        else
            printf("%I64d*x^%I64d",temp->index_num,temp->coefficient_num);
        temp=temp->next;
    }
    printf("\n");
}

//����ĸ���
LinkList Copy_LinkList(LinkList a)
{
    LinkList b,temp,temp1,temp2;
    b=(LinkList)malloc(sizeof(LinkNode));
    temp1=b;
    temp=a->next;
    while(temp!=NULL)
    {
        temp2=(LinkList)malloc(sizeof(LinkNode));
        temp1->next=temp2;
        temp2->coefficient_num=temp->coefficient_num;
        temp2->index_num=temp->index_num;
        temp2->next=NULL;
        temp1=temp2;
        temp2=temp1->next;
        temp=temp->next;
    }
    return b;
}

//����һԪ����ʽ�����
LinkList Add_LinkList(LinkList a,LinkList b)
{
    LinkList temp,temp1=a->next,temp2=b->next;
    LinkList c,temp3;
    c=(LinkList)malloc(sizeof(LinkNode));
    //�Ƚ�����b���Ƶ�����c
    c=Copy_LinkList(b);
    //������a������������뵽c��
    while(temp1!=NULL)
    {
        temp=(LinkList)malloc(sizeof(LinkNode));
        temp->coefficient_num=temp1->coefficient_num;
        temp->index_num=temp1->index_num;
        temp->next=NULL;
        temp2=c;
        while(temp2->next!=NULL && ((temp2->next)->coefficient_num)<(temp->coefficient_num))
        {
            temp2=temp2->next;
        }
        if(temp2->next==NULL)
        {
            temp->next=NULL;
            temp2->next=temp;
        }
        else
        {
            if(temp2->next->coefficient_num==temp->coefficient_num)
            {
                temp3=temp2->next;
                temp3->index_num+=temp->index_num;
                //��ϵ��Ϊ0ʱ��ȥ����
                if(temp3->index_num==0)
                {
                    temp2->next=temp3->next;
                    free(temp3);
                }
            }
            else
            {
                temp->next=temp2->next;
                temp2->next=temp;
            }
        }
        temp1=temp1->next;
    }
    return c;
}

//����һԪ����ʽ�����
LinkList subtract_LinkList(LinkList a,LinkList b)
{
    LinkList temp,temp1=a->next,temp2=b->next;
    LinkList c,temp3;
    c=(LinkList)malloc(sizeof(LinkNode));
    //�Ƚ���������a���Ƶ�����c
    c=Copy_LinkList(a);
    //������b�����ݵ�ϵ�����ϸ��ź�������뵽c��
    while(temp2!=NULL)
    {
        temp=(LinkList)malloc(sizeof(LinkNode));
        temp->coefficient_num=temp2->coefficient_num;
        temp->index_num=-temp2->index_num;
        temp->next=NULL;
        temp1=c;
        while(temp1->next!=NULL && ((temp1->next)->coefficient_num)<(temp->coefficient_num))
        {
            temp1=temp1->next;
        }
        if(temp1->next==NULL)
        {
            temp->next=NULL;
            temp1->next=temp;
        }
        else
        {
            if(temp1->next->coefficient_num==temp->coefficient_num)
            {
                temp3=temp1->next;
                temp3->index_num+=temp->index_num;
                //��ϵ��Ϊ0ʱ��ȥ����
                if(temp3->index_num==0)
                {
                    temp1->next=temp3->next;
                    free(temp3);
                }
            }
            else
            {
                temp->next=temp1->next;
                temp1->next=temp;
            }
        }
        temp2=temp2->next;
    }
    return c;
}

//����һԪ����ʽ���
LinkList Mul_LinkList(LinkList a,LinkList b)
{
    LinkList temp1,temp2,temp3,temp4;
    LinkList c=NULL,d=NULL;
    temp1=a->next;
    while(temp1!=NULL)
    {
        //��b���Ƶ�c
        c=Copy_LinkList(b);
        //��temp1��c�и������
        temp2=c;
        while(temp2->next!=NULL)
        {
            //��temp1��temp2->next���
            temp2->next->coefficient_num+=temp1->coefficient_num;
            temp2->next->index_num*=temp1->index_num;
            //��ϵ��Ϊ0ʱ��ȥ����
            if(temp2->next->index_num==0)
            {
                temp3=temp2->next;
                temp2->next=temp3->next;
                free(temp3);
            }
            //c����һ��
            temp2=temp2->next;
        }
        //���˺�Ľ����֮ǰ�����
        if(d==NULL)
            d=c;
        else
        {
            d=Add_LinkList(c,d);
            //�ͷ�����c
            temp4=c->next;
            while(temp4!=NULL)
            {
                free(c);
                c=temp4;
                temp4=temp4->next;
            }
        }
        //a����һ��
        temp1=temp1->next;
    }
    return d;
}

//����һԪ����ʽ��ֵ
long long int Cal_LinkList(LinkList a,long long int x)
{
    long long int sum=0;
    LinkList temp1;
    temp1=a->next;
    while(temp1!=NULL)
    {
        sum+=(temp1->index_num*quickpow(x,temp1->coefficient_num));
        sum%=N;
        temp1=temp1->next;
    }
    return sum;
}

//һԪ����ʽ����
LinkList Der_LinkList(LinkList a)
{
    LinkList b,temp1,temp2,temp3;
    temp1=a->next;
    b=(LinkList)malloc(sizeof(LinkNode));
    b->next=NULL;
    temp3=b;
    while(temp1!=NULL)
    {
        temp2=(LinkList)malloc(sizeof(LinkNode));
        //������ֱ������
        if(temp1->coefficient_num==0)
            temp1=temp1->next;
        else
        {
            temp3->next=temp2;
            temp2->coefficient_num=temp1->coefficient_num-1;
            temp2->index_num=(temp1->index_num*temp1->coefficient_num);
            temp2->next=NULL;
            temp3=temp2;
            temp2=temp3->next;
            temp1=temp1->next;
        }
    }
    return b;
}

//��ʾ��ӡ
void print_hint()
{
    printf("��ӭʹ��һԪ����ʽ������������ϸ�Ķ����¹���\n");
    printf("1������ֻ��һԪ��������һ����x����δ֪����\n");
    printf("2�������е���ֵ�����������10^10�ڼ��㣬������Χ����֤���ȡ�\n");
    printf("3������ֻ����ָ��Ϊ���Ķ���ʽ���㡣\n");
    printf("4���Ѿ�����Ӧ�������뷽ʽ�����ϸ����������ʽ�������׳���\n");
    return ;
}

void menu()
{
    LinkList s1,s2;
    int choose;
    long long int x;
    print_hint();
    printf("��������������Ҫ�������������ʽ��\n");
    printf("�����ʽ������x+1;2x2+3x^2...\n");
    printf("s1=");
    s1=Create_LinkList();
    printf("s2=");
    s2=Create_LinkList();
    while(1)
    {
        printf("������ѡ����Ҫ���еļ��㡣\n");
        printf("1����ӣ�\n2�������\n3����ˣ�\n4����ֵ��\n5���󵼣�\n6���������ʽ��\n0���˳���\n");
        scanf("%d",&choose);
        switch(choose)
        {
        case 1:
            printf("s1+s2=");
            Print_LinkList(Add_LinkList(s1,s2));
            system("pause");
            break;
        case 2:
            printf("s1-s2=");
            Print_LinkList(subtract_LinkList(s1,s2));
            printf("s2-s1=");
            Print_LinkList(subtract_LinkList(s2,s1));
            system("pause");
            break;
        case 3:
            printf("s1*s2=");
            Print_LinkList(Mul_LinkList(s1,s2));
            system("pause");
            break;
        case 4:
            scanf("%I64d",&x);
            printf("s1=%I64d\ns2=%I64d\n",Cal_LinkList(s1,x),Cal_LinkList(s2,x));
            system("pause");
            break;
        case 5:
            printf("(s1)'=");
            Print_LinkList(Der_LinkList(s1));
            printf("(s2)'=");
            Print_LinkList(Der_LinkList(s2));
            system("pause");
            break;
        case 6:
            printf("s1=");
            Print_LinkList(s1);
            printf("s2=");
            Print_LinkList(s2);
            system("pause");
            break;
        case 0:
            printf("�˳���...\n");
            return ;
        default:
            printf("��������\n");
            system("pause");
            break;
        }
        system("cls");
        print_hint();
    }
    return ;
}

int main()
{
    menu();
    return 0;
}
