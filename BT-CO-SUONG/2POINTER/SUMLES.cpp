#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init()
{
    freopen("SUMLES.INP", "r", stdin);
    freopen("SUMLES.OUT", "w", stdout);
    fast;
}
KING_PHAT
{
    init();
    fast;
    int n, s;
    cin >> n >> s;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    
    ll l = 0, r = 0, current = 0, maxlen = LLONG_MIN;

    while (r < n) {
        current += a[r];
        while (current > s && l <= r) {
            current -= a[l];
            l++;
        }
        if (current <= s) {
            maxlen = max(maxlen, r - l + 1);
        }
        
        r++;
    }

    cout << maxlen << endl;
}
