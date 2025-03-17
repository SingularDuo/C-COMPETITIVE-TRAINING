#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

void init()
{
    freopen("SDIGIT.inp", "r", stdin);
    freopen("SDIGIT.out", "w", stdout);
    fast;
}

bool isPrime(int x) {
    if (x <= 1) return false;
    if (x <= 3) return true;
    if (x % 2 == 0 || x % 3 == 0) return false;
    for (int i = 5; i * i <= x; i += 6) {
        if (x % i == 0 || x % (i + 2) == 0) return false;
    }
    return true;
}

bool isSdigit(ll x) {
    ll res = 0;
    while (x) {
        res += x % 10;
        x /= 10;
    }
    return isPrime(res);
}

KING_PHAT
{
    init();
    fast;
    int t;
    cin >> t;
    
    vector<ll> l(t), r(t);
    ll max_r = 0;
    for (int i = 0; i < t; i++) {
        cin >> l[i] >> r[i];
        max_r = max(max_r, r[i]);
    }
    vector<ll> power10(20, 1);
    for (int i = 1; i < 20; i++) power10[i] = power10[i - 1] * 10;
    for (int i = 0; i < t; i++) {
        ll start = power10[l[i] - 1];
        ll end = power10[r[i]] - 1;
        ll res = 0;
        
        for (ll num = start; num <= end; num++) {
            if (isSdigit(num)) res++;
        }
        cout << res << endl;
    }
    
    return 0;
}
