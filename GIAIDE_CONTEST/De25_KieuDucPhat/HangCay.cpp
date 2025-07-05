/*
 * Author: Kduckp
 * Generated on: 2025-05-30 23:03:47
*/

#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

int n, m;
const int MAXN = 2005;
bool mark[MAXN];

signed main() {
    freopen("HangCay.Inp", "r", stdin);
    freopen("HangCay.Out", "w", stdout);
    fast;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        int x, r;
        cin >> x >> r;

        int left = max(1LL, x - r);
        int right = min(n, x + r);

        for (int j = left; j <= right; j++) {
            mark[j] = true;
        }
    }

    int count = 0;
    for (int i = 1; i <= n; i++) {
        if (mark[i]) count++;
    }

    cout << count << endl;
    return 0;
}
