#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

KING_PHAT
{
    fast;
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        string s;
        cin>>s;
        vector<ll> penalty(n);
        for(int i = 0; i < n; i++)cin>>penalty[i];
        ll determine = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == 'B')determine++;
        }
        if(determine <= k)
        {
            ll maxx = LLONG_MIN;
            ll times = 0;
            for(int i = 0; i < s.size(); i++)
            {
                if(s[i] == 'R')
                {
                    times++;
                    if(times == 1)continue;
                    maxx = max(maxx, penalty[i]);
                }
            }
            cout<<maxx<<endl;
            continue;
        }
        else{
            ll sizee = s.size();
            for(int i = 0; i < n; i++)
            {
                if(s[i] == 'B'){
                    ll idx = i, curr = 0;
                    while(s[idx] == 'B' && idx + 1 <= sizee)
                    {
                        s.erase(idx,1);
                        idx++;
                        sizee--;
                        curr++;
                    }
                }
            }
            for(int i = 0; i < sizee; i++)
            {
                if(s[i] == 'B'){
                    k--;
                    s[i] = 'x';
                }
                if(k == 0)break;

            }
            ll res = LLONG_MAX;
            for(int i = 0; i < sizee; i++)
            {
                if(s[i] != 'x')
                {
                    res = min(res, penalty[i]);
                }
            }
            cout<<res<<endl;
        }
    }
}