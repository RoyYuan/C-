#include <iostream>
#include <cstring>
#include <cstdio>
#include <algorithm>
#include <map>

using namespace std;

int N,M;
int start,sum;
map <string,int> Visit;
string n[200005];
int main ()
{
    int i=1;
    sum=0;
    start=1;
    cin >> N >> M;
    while(i<=N)
    {
        cin >> n[i];
        if(Visit[n[i]] >=start && Visit[n[i]]<i)
        {
            cout << "Cache" << endl;
        }
        else
        {
            cout << "Internet" << endl;
            sum++;
            if(sum>M)
            {
                start++;
            }
        }
        Visit[n[i]]=i;
        while(Visit[n[start]]!=start)
            start++;
        i++;
    }
    return 0;
}
