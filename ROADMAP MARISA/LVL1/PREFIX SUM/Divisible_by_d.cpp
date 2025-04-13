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
    int n, d;
    cin >> n >> d;
    vector<ll> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<ll> prefix(n + 1, 0);
    unordered_map<ll, ll> count;
    count[0] = 1; 

    ll ans = 0;
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + a[i - 1]; 

        ll r = (prefix[i] % d + d) % d; 
        ans += count[r]; 

        count[r]++;
    }

    cout << ans << endl;
}
