#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init()
{
    freopen("PAIR.inp","r", stdin);
    freopen("PAIR.out", "w", stdout);
    fast;
}
KING_PHAT
{
    init();
    fast;
    int n, s;
    cin>>n>>s;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    sort(a.begin(), a.end());
    int l = 0, r = 0, current = 0;
    int res =0;
    while(r < n -1)
    {
        r++;
        if(l == r)continue;
        current = a[l] + a[r];
        if(current  > s)l--;
        else
        {
            res++;
            l++;
            r--;
        }

    }
    cout<<res;
}