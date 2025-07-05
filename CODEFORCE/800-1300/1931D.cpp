#include <bits/stdc++.h>
using namespace std;

#define int long long

signed main() {
    ios::sync_with_stdio(0); cin.tie(0);
    int t; cin >> t;
    while (t--) {
        int n, x, y;
        cin >> n >> x >> y;
        vector<int> a(n);
        map<pair<int, int>, int> cnt;
        int res = 0;

        for (int i = 0; i < n; ++i) {
            cin >> a[i];
            int s = (-a[i] % x + x) % x;
            int d = a[i] % y;           

            pair<int, int> key = {s, d};
            res += cnt[key];

            pair<int, int> mykey = {a[i] % x, a[i] % y};
            cnt[mykey]++;
        }

        cout << res << '\n';
    }
}
