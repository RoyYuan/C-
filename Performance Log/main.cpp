#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <algorithm>
#include <map>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

const int N = 20000 + 5;

// 存储节点
struct Node
{
    string func;
    string state;
    string ti;
    int timestamp;

};
Node node[N];

// 存储答案
struct Ans
{
    string func;
    int gap;
    string timelast;
};
Ans ans[N/2];

int nlist;

// 判断START和END的先后顺序
// 判断时间的先后顺序
bool is_invalid()
{
    map<string, int> mp;
    int cnt = 0;
    for(int i = 1; i <= nlist; i ++)
    {
        if(node[i].timestamp < cnt) return true;
        cnt = node[i].timestamp;
        if(!mp[node[i].func])
        {
            if(node[i].state.compare("END") == 0) return true;
            mp[node[i].func] = i;
        }
        else
        {
            if(node[i].state.compare("END") != 0) return true;
        }
    }

    return false;
}

// 时间格式转化为整数
void transform_timestamp(string ti, int id)
{
    int hour = (ti[0] - '0') * 10 + (ti[1] - '0');
    int mins = (ti[3] - '0') * 10 + (ti[4] - '0');
    int sec  = (ti[6] - '0') * 10 + (ti[7] - '0');
    node[id].timestamp = sec + mins * 60 + hour * 3600;
}

// 整数转换为时间格式
void trans_time(int gap, int idx)
{
    int secs = gap % 60;
    gap /= 60;
    int mins = gap % 60;
    gap /= 60;
    int hour = gap % 60;
    string zero("0");
    string dot(":");
    char temp[20];

    sprintf(temp, "%d", secs);
    string tmp(temp);
    string secs_string = secs < 10 ? zero + tmp.c_str() : tmp.c_str();

    sprintf(temp, "%d", mins);
    string tmp1(temp);
    string mins_string = mins < 10 ? zero + tmp1.c_str() : tmp1.c_str();

    sprintf(temp, "%d", hour);
    string tmp2(temp);
    string hour_string = hour < 10 ? zero + tmp2.c_str() : tmp2.c_str();

    ans[idx].timelast = hour_string + dot + mins_string + dot + secs_string;
    return;
}

// 利用栈进行模拟，mp记录的原来数组的下标
// mp1记录的是栈出现元素的先后顺序，用于输出
// 继续判断是否合法，类似括号匹配，以及栈是否非空
void solve()
{
    stack<string>st;
    map<string, int> mp;
    map<string, int> mp1;
    int idx = 2;
    int ans_idx = 2;
    st.push(node[1].func);
    mp[node[1].func] = 1;
    mp1[node[1].func] = 1 ;
    ans[1].func = node[1].func;
    bool flag = false;
    while(!st.empty() && idx <= nlist)
    {
        if(!mp[node[idx].func])
        {
            ans[ans_idx].func = node[idx].func;
            mp[node[idx].func] = idx;
            mp1[node[idx].func] = ans_idx ++ ;
            st.push(node[idx].func);
        }
        else
        {
            string frt = st.top();
            if(frt.compare(node[idx].func) != 0)
            {
                flag = true;
                break;
            }
            st.pop();
            ans[mp1[frt]].gap = node[idx].timestamp - node[mp[frt]].timestamp;
        }
        idx ++;
    }
    if(flag || !st.empty())
    {
        printf("Incorrect performance log\n");
        return;
    }

    // 转换为时间格式
    for(int i = 1; i < ans_idx; i ++)
    {
        trans_time(ans[i].gap, i);
    }
    for(int i = 1; i < ans_idx; i ++  )
    {
        cout << ans[i].func << " " << ans[i].timelast << endl;
    }

}

int main()
{
    cin >> nlist;
    string s1, s2, s3;
    for(int i = 1; i <= nlist; i ++)
    {
        cin >> node[i].func >> node[i].ti >> node[i].state;
        transform_timestamp(node[i].ti, i);
    }

    if(is_invalid())
    {
        printf("Incorrect performance log\n");
        return 0;
    }

    solve();

    return 0;
}
