#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5;
#define int long long
signed main() {

    freopen("DAYSO.inp", "r", stdin);
    freopen("DAYSO.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, x;
    vector<int> a(maxn + 5, 0);
    unordered_map<int, int> m;

    cin >> n >> x;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        m[a[i]]++;
    }
    long long res = 0;
    for (int i = 1; i <= n; i++) {
        int t = sqrt(x - a[i]);
        if (t * t == x - a[i]) {
            if (m[t] > 0) {
                res += m[t];
            }
        }
        m[a[i]]--;
    }
    cout << res;

    return 0;
}
