#include<bits/stdc++.h>

using namespace std;
#define ll long long
#define int long long
#define endl "\n"
void init()
{
    freopen("VNI.inp", "r", stdin);
    freopen("VNI.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
                cout.tie(0);
}
vector<int> gen(const vector<int>& a) {
    int n = a.size();
    if (n == 0) return {};
    vector<ll> sub  = a;
    sort(sub.begin(), sub.end());
    vector<int> dp(n, 0);
    int min_price = sub[0];

    for (int i = 1; i < n; i++) {
        dp[i] = max(dp[i - 1], a[i] - min_price);
        min_price = min(min_price, a[i]);
    }

    return dp;
}

signed main() {
    init();
    int n;
    cin>>n;
    vector<ll> a(n);
    for(int i = 0; i < n; i++)cin>>a[i];
    vector<int> res = gen(a);
    int q;cin>>q;
    while(q--)
    {
        int x;
        cin>>x;
        cout<<res[x-1]<<endl;
    }
    return 0;
}
