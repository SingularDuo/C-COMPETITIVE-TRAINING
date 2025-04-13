#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init()
{
    freopen("TKNP4.txt", "r", stdin);
    freopen("TKNP4.txt", "w", stdout);

}
KING_PHAT
{
    init();
    fast;
    int n, q;
    cin>>n>>q;
    vector<ll> a(n+1);
    map<int, vector<int>> cnt;
    for(int i = 1; i <= n; i++)
    {
        cin>>a[i];
        cnt[a[i]].push_back(i);
    }
    while(q--)
    {
        int l,r,x;
        cin>>x;
        l = 0;
        r = n;
        auto it = lower_bound(cnt[x].begin(), cnt[x].end(), l);
        auto it2 = upper_bound(cnt[x].begin(), cnt[x].end(), r);
        if(it == it2)cout<<0<<endl;
        else cout<<it2 - it<<endl;
    }
}