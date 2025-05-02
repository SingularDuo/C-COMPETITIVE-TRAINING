#include <bits/stdc++.h>
using namespace std;
#define int long long
#define KING_PHAT signed main()
#define fast ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define endl '\n'

void solve() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }

        vector<int> dp(n, 0);
        dp[0] = a[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i - 1], a[i]);
        }

        vector<int> result;
        int s = 0;
        for (int i = n - 1; i >= 0; i--) {
            s += a[i];
            if (i > 0) {
                cout << max(s, s - a[i] + dp[i-1]) << " ";
            } else {
                cout << s << " "; 
            }
        }
        cout << endl;
    }
}

KING_PHAT {
    fast;
    solve();
    return 0;
}
