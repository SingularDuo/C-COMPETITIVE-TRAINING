#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

const int MOD = 1e9 + 7;

int a, b, n, m;
set<int> sums;

signed main() {
    fast;
    freopen("WOOD.INP", "r", stdin);
    freopen("WOOD.OUT", "w", stdout);

    cin >> a >> b >> n >> m;

    if (n == 1 && m == 1) {
        if (a == b) {
            cout << 2;
        } else {
            cout << 3;
        }
        return 0;
    }

    if (a == b) {
        cout << (n + m) % MOD;
        return 0;
    }

    if (m == 1) {
        if (b % a == 0) {
            cout << n * 2;
        } else {
            cout << n * 2 + 1;
        }
        return 0;
    }

    set<int> cnt;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= m; j++) {
            int current = i * a + j * b;
            cnt.insert(current);
        }
    }

    cout << (cnt.size() - 1) % MOD;
    return 0;
}
