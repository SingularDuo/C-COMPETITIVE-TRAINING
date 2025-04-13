#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long
#define int long long
void init() {
    freopen("DIV.inp", "r", stdin);
    freopen("DIV.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

signed main() {
    init();
    ll n;
    cin >> n;
    vector<ll> a(n);
    int sum = 0;
    for(int i = 0; i < n; i++)
    {
        cin>>a[i];
        sum+= a[i];
    }
    ll res = -1;
    for(int i = 1; i <= n; i++)
    {
        int avg = sum / i;
        vector<ll> current(i, 0);
        ll idx = 0, multi = 1;
        ll ava = true;
        for(int j = 0; j < n; j++)
        {
            if(current[idx] + a[j] > avg * multi)
            {
                ava = false;
                break;
            }
            else if(current[idx] == avg*multi)
            {
                idx++;
                multi++;
            }
        }
        if(ava)res = max(res, i);

    }
    cout<<res;
}
