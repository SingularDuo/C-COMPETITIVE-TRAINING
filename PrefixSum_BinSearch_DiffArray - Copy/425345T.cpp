#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define int long long
#define vi vector<int>
#define FOR(i,n) for (int i = 0; i < n; ++i)

signed main() {
    fast;

    int n;
    cin >> n;
    vi a(n), d(n + 2, 0); 

    FOR(i, n) cin >> a[i];

    int q;
    cin >> q;
    while (q--) {
        int l, r, x;
        cin >> l >> r >> x;
        --l; --r;
        d[l] += x;
        d[r + 1] -= x;
    }

    // áp dụng d vào a
    int delta = 0;
    FOR(i, n) {
        delta += d[i];
        a[i] += delta;
    }

    FOR(i, n) cout << a[i] << " ";
    cout << "\n";
}
