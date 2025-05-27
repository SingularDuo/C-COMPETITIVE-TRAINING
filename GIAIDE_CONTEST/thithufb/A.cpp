#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define endl "\n"
#define int long long

signed main()
{
    freopen("input.inp", "r", stdin);
    freopen("output.out", "w", stdout);
    string s1, s2;
    cin>>s1>>s2;

    map<char, int> cnt;
    for(int i = 0; i < s1.size(); i++)cnt[s1[i]]++;

    int res = 0;
    for(int i = 0; i < s2.size(); i++)
    {
        if(cnt[s2[i]] == 0)res++;
    }
    cout<<res;
}
