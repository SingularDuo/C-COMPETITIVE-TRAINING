#include <bits/stdc++.h>
using namespace std;
#define int long long
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

signed main() {
    fast;
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n + 1, vector<int>(m + 1, 0));
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            cin >> a[i][j];
        }
    }
    // e anh Trong doc code nay thi bt la Kadane nhe
    int res = LLONG_MIN;
    for (int top = 1; top <= n; top++) {
        vector<int> temp(m + 1, 0);
        for (int bottom = top; bottom <= n; bottom++) {
            for (int col = 1; col <= m; col++) {
                temp[col] += a[bottom][col];
            }
            int maxx = LLONG_MIN, curr = 0;
            for (int col = 1; col <= m; col++) {
                curr = max(temp[col], curr + temp[col]);
                maxx = max(maxx, curr);
            }
            res = max(res, maxx);
        }
    }

    cout << res << endl;
    return 0;
}
