#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'
void init()
{
    freopen("BAI2.INP", "r", stdin);
    freopen("BAI2.OUT", "w", stdout);
    fast;
}
void solve(long long n, long long m) {
    vector<ll> a;
    ll start = max(1LL, (m - n * (n - 1) / 2) / n);
    ll sum = 0;
    for (int i = 0; i < n; i++) {
        a.push_back(start + i);
        sum += a.back();
    }
    if (sum == m) {
        cout << a[0] << " " << a.back() << endl;
        return;
    } else {
        ll idx = a.size() - 1;
        ll du = m - sum;
        while (du > 0) {
            a[idx]++;
            du--;
            idx--;
            if (idx < 0) idx = a.size() - 1;
        }
        cout << a[0] << " " << a.back() << endl;
        return;
    }
    cout<<-1;
}

signed main() {
    init();
    fast;
    long long n, m;
    cin >> n >> m;
    if (n == 2) {
        cout << m / 2 - !(m % 2) << " " << m / 2 + 1 << endl;
        return 0;
    }
    solve(n, m);
    return 0;
}
