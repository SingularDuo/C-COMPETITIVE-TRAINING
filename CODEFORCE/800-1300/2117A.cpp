#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll long long
#define endl "\n"
#define min(a, b) min((ll)a, (ll)b)
#define max(a, b) max((ll)a, (ll)b)
#define fi first
#define se second
#define si size()
#define all(x) x.begin(), x.end()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ull unsigned long long
#define pb push_back
#define __TOISETHIVOI__ signed main()

const int MOD = 1e9 + 7;
const int INF = 2 * 1e18;

void init() {
  freopen("input.inp", "r", stdin);
  freopen("output.out", "w", stdout);
  fast;
}

__TOISETHIVOI__ {
    int t; cin >> t;
    while (t--) {
        int n, x; cin >> n >> x;
        vector<ll> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        if (x >= n) {
            cout << "YES" << endl;
            continue;
        }

        bool ok = false;
        for (int i = 0; i <= n - x; i++) {
            bool valid = true;

            for (int j = 0; j < i; j++) {
                if (a[j] == 1) valid = false;
            }
            for (int j = i + x; j < n; j++) {
                if (a[j] == 1) valid = false;
            }
            if (valid) {
                ok = true;
                break;
            }
        }

        cout << (ok ? "YES" : "NO") << endl;
    }
    return 0;
}
