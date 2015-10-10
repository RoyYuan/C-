    #include <iostream>
    #include <string.h>
    #include <algorithm>
    #include <stdio.h>

    using namespace std;
    const int N = 5005;
    const int INF = ~0U>>1;

    struct Node
    {
        int x,y;
    };

    Node a[N],t[N];
    int d[N];

    bool cmp(Node a,Node b)
    {
        return a.x < b.x || (a.x == b.x && a.y < b.y);
    }

    int Binary_Search(int l,int r,int x)
    {
        while(l < r)
        {
            int m = (l + r) >> 1;
            if(x <= d[m]) r = m;
            else l = m + 1;
        }
        return l;
    }

    int Work(Node a[],int n)
    {
        d[0] = -1;
        int max = -1;
        int len = 1;
        for(int i=1;i<=n;i++)
        {
            d[len] = INF;
            int j = Binary_Search(0,len,a[i].y);
            if(j == len) len++;
            d[j] = a[i].y;
        }
        return len - 1;
    }

    int main()
    {
        int n,T;
        scanf("%d",&T);
        while(T--)
        {
            scanf("%d",&n);
            for(int i=1;i<=n;i++)
                scanf("%d%d",&a[i].x,&a[i].y);
            sort(a+1,a+n+1,cmp);
            for(int i=1;i<=n;i++)
               t[n-i+1] = a[i];
            printf("%d\n",Work(t,n));
        }
        return 0;
    }
