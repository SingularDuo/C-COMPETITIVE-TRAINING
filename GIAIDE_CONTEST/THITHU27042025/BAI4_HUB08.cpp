#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define endl "\n"

void init() {
    freopen("BAI4_HUB08.inp", "r", stdin);
    freopen("BAI4_HUB08.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
}

signed main() {
    init();

    ll n, k, s = 0;
    cin >> n;
    vector<ll> a(n + 1), f(n + 1, 0);

    for (ll i = 1; i <= n; i++) {
        cin >> a[i];
        s += a[i];
        f[i] = f[i - 1] + a[i];
    }

    k = (s+1)/2;
    ll res = LLONG_MAX;
    ll l = 1;
    for (ll r = 1; r <= n; r++) {
        
        //cout<<"r: "<<r<<endl;
        while (f[r] - f[l] > k && l <= r) 
        {
            //cout<<l<<" "<<r<<endl;
            l++;
        }
        //while(f[r] - f[l-1] < k)l--;
        //cout<<"done loop"<<endl; 
        //cout<<l<<" "<<r<<endl;
        if (f[r] - f[l - 1] < k) continue;
        //cout<<"valid "<<l<<" "<<r<<endl;

        ll v = f[r] - f[l - 1];
        //cout<<v<<endl;
        if (v == k) {
            //cout<<"v = k"<<endl;
            res = min(res, r - l + 1);
        } else {
            //cout<<"get "<<l<<" "<<r<<endl;
            //cout<<l<<" "<<r<<endl;
            
            ll du = v - k;
            ll minn = LLONG_MAX;
            for(ll i  = l; i <= r; i++)minn = min(minn, a[i]);
            if(v - minn >= k)res = min(res, r - l);
            else res = min(res, r - l + 1);
        }
    }

    cout << res << endl;
    return 0;
}
