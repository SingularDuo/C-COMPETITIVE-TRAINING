#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
void init()
{
    freopen("MA_B6.inp", "r", stdin);
    freopen("MA_B6.out", "w", stdout);
}
ll cntz(ll n) {
    ll count = 0;
    while (n > 0) {
        count += n / 5;
        n /= 5;
    }
    return count;
}

signed main() {
    init();
    fast;
    ll n;
    cin >> n;
    cout << cntz(n);
    return 0;
}
