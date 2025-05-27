#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define int long long
#define endl "\n"
vector<char> nguyen = {'a', 'e', 'i', 'o', 'u'};

bool IsNguyen(char s)
{
    for(int i = 0; i < 5; i++)
    {
        if(s == nguyen[i])return true;
    }
    return false;
}
bool IsPhu( char s)
{
    for(int i = 0; i < 5; i++)
    {
        if(s == nguyen[i])return false;
    }
    return true;
}
signed main()
{
    freopen("09B.INP", "r", stdin);
    freopen("09B.ans", "w", stdout);
    string s; cin>>s;

    ll res = 0;

    for(int i = 0; i < s.size(); i++)
    {
        for(int j = i + 1; j < s.size(); j++)
        {
            if((IsNguyen(s[i]) && IsPhu(s[j])) || (IsPhu(s[i]) && IsNguyen(s[j])))res++;
        }
    }
    cout<<res;
}