#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define int long long
signed main()
{
    string s;
    cin>>s;
    ll res = LLONG_MIN;
    for(int i = 0; i< s.size(); i++)
    {
        char current = s[i];
        ll ans =0;
        ll idx = i;
        while(s[idx] == current)
        {
            idx++;
            ans++;
        }
        res = max(res, ans);
    }
    cout<<res;
}
