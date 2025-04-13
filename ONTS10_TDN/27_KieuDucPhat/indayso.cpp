#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define int long long
void init() {
    freopen("indayso.inp", "r", stdin);
    freopen("indayso.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

signed main() {
    init();
    int n, k;
    cin>>n>>k;
    vector<ll> a(n);
    map<int, int>cnt;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        cnt[a[i]]++;
    }
    bool ap = false;
    for(auto& i : cnt)
    {
        if(i.second >= k)
        {
            ap = true;
            cout<<i.first<<" ";
        }
    }
    if(!ap)cout<<"NO";
}
